; File: bookcmp.asm
;
;Defines the bookcmp subroutine for use by the sort algorithm in sort_books.c
;
%define AUTHOR_OFFSET 0
%define TITLE_OFFSET 21
%define SUBJECT_OFFSET 54
%define YEAR_OFFSET 68
	

        SECTION .text                   ; Code section.
        global  bookcmp                 ; let loader see entry point

bookcmp: 
	push	ebp			; push registers we want to use

	mov	ebp, esp
	
	push	edi
	push	esi

	mov	ecx, [ebp + 8]		; get the pointer to the first book
	mov	edx, [ebp + 12]		; get the pointer to the second book

	mov	eax, [ecx + YEAR_OFFSET]; fetch book1's year field
	sub	eax, [edx + YEAR_OFFSET]; and "compare" the to book2's year
	jnz	allDone			; If they're different, we're done
					; with comparisons

cmpTitles:				; Fall through to here if years same
	;; Following could also be done using "lea" instruction
	mov	edi, ecx		; Get address of book1's title
	add	edi, TITLE_OFFSET
	mov	esi, edx		; Get address of book2's title
	add	esi, TITLE_OFFSET
	mov	eax, 0			; Pre-clear all 32 bits of eax

L1:	mov	al, [edi]		; Fetch next char of book1's title
	sub	al, [esi]		; and compare it to matching char in
					; book 2
	jne	titleCmpDone		; If we find a difference, we are done
					; (note this also works if one string
					; or other at NULL)

	;; So far, all chars equal; see if we are at end (i.e., check for NULL)
	cmp	byte [edi], 0
	je	titleCmpDone
	inc	edi
	inc	esi
	jmp	L1

titleCmpDone:
	movsx	eax, al			; need to convert 8-bit to full 32-bit

allDone:				; Clean up and finish
	;; Note that eax already has an appropriate value <0, =0, or >0
	pop	esi
	pop	edi
	pop	ebp
	ret
