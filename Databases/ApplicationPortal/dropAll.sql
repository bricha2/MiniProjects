use jupyter;

#DELETE FROM `jupyter`;
SET SQL_SAFE_UPDATES=0;
DELETE FROM `evaluation`;
DELETE FROM `possibleanswers`;
DELETE FROM `possiblescores`;
DELETE FROM `rubric`;
DELETE FROM `reqt`;
DELETE FROM `application`;
DELETE FROM `program`;
DELETE FROM `applicant`;

DROP TABLE ApplicantPhone;
DROP TABLE GRE;
DROP TABLE priorEducation;
DROP TABLE lettersOfRef;
DROP TABLE PossibleScores;
DROP TABLE PossibleAnswers;
DROP TABLE Scores;
DROP TABLE satisfies;
DROP TABLE Reqt;
DROP TABLE Rubric;
DROP TABLE Evaluation;
DROP TABLE Application;
DROP TABLE Program;
DROP TABLE Applicant;

