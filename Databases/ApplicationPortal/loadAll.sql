use `jupyter`;

# Populate the tables with data for
# 	At least five applications, three applicants, and two application evaluations by faculty
# 	At least two degree programs, each with one rubric and at least two program requirements
# 	At least two rubrics, each with at least two evaluation criteria.
# The demonstration should include all the functional user requirements. 

# Creation of Applicants
INSERT INTO `jupyter`.`applicant`
(`gender`,`DOB`,`fName`,`mInitial`,`lName`,`email`,`street`,`city`,`state`,`zipcode`)
VALUES
('Female',date '1996-05-30','Brianna','K','Richardson','bkr@umbc.edu','1000 Hilltop Circle','Baltimore','MD',21755);

INSERT INTO `jupyter`.`applicant` 
(`gender`,`DOB`,`fName`,`mInitial`,`lName`,`email`,`street`,`city`,`state`,`zipcode`)
VALUES
('Male',date '1996-08-14','Durell','J','Smith','djs@umbc.edu','1001 Hilltop Circle','Baltimore','MD',21755);

INSERT INTO `jupyter`.`applicant` 
(`gender`,`DOB`,`fName`,`mInitial`,`lName`,`email`,`street`,`city`,`state`,`zipcode`)
VALUES
('Female', date '1990-01-12', 'Claire', 'D', 'Eunice', 'cde@domain.com','1002 Hilltop Circle','Baltimore','MD',21755);

# creation of programs
INSERT INTO `jupyter`.`program`
(`pName`,`dept`,`phone`)
VALUES('Computer Science','Department of Computer Science','4104553500');

INSERT INTO `jupyter`.`program`
(`pName`,`dept`,`phone`)
VALUES('Chemistry','Department of Chemistry & Biochemistry','4104552491');

# Creation of application
INSERT INTO `jupyter`.`application`
(`semester`,`startYear`,`pid`,`pName`)
VALUES('Fall',2018, 1, 'Computer Science');

INSERT INTO `jupyter`.`application`
(`semester`,`startYear`,`pid`,`pName`)
VALUES('Fall',2018, 1, 'Chemistry');

INSERT INTO `jupyter`.`application`
(`semester`,`startYear`,`pid`,`pName`)
VALUES('Fall',2018, 2, 'Computer Science');

INSERT INTO `jupyter`.`application`
(`semester`,`startYear`,`pid`,`pName`)
VALUES('Fall',2018, 2, 'Chemistry');

INSERT INTO `jupyter`.`application`
(`semester`,`startYear`,`pid`,`pName`)
VALUES('Fall',2018, 3, 'Computer Science');

INSERT INTO `jupyter`.`application`
(`semester`,`startYear`,`pid`,`pName`)
VALUES('Spring',2018, 3, 'Chemistry');


# Create Prior Education
INSERT INTO `jupyter`.`prioreducation`
(`university`,`major`,`degree`,`gradDate`,`gpa`,`aid`)
VALUES
('UMBC', 'Information Science', 'BS', date '2015-05-15', 3.4, 1);

INSERT INTO `jupyter`.`prioreducation`
(`university`,`major`,`degree`,`gradDate`,`gpa`,`aid`)
VALUES
('UMBC', 'Health Information Technology', 'MS', date '2017-05-15', 4.0, 1);

INSERT INTO `jupyter`.`prioreducation`
(`university`,`major`,`degree`,`gradDate`,`gpa`,`aid`)
VALUES
('Towson', 'Chemistry', 'BS', date '2014-05-04', 3.9, 2);

INSERT INTO `jupyter`.`prioreducation`
(`university`,`major`,`degree`,`gradDate`,`gpa`,`aid`)
VALUES
('Morgan', 'Biology', 'MS', date '2017-05-20', 3.9, 2);

INSERT INTO `jupyter`.`prioreducation`
(`university`,`major`,`degree`,`gradDate`,`gpa`,`aid`)
VALUES
('Towson', 'Biology', 'BS', date '2017-05-20', 2.0, 3);

# Create Rubric
INSERT INTO `jupyter`.`rubric`
(`criteria`,`pName`)
VALUES
('GPA', 'Computer Science');

INSERT INTO `jupyter`.`rubric`
(`criteria`,`pName`)
VALUES
('priorEducation', 'Chemistry');

# Possible Scores
INSERT INTO `jupyter`.`possiblescores`
(`score`,`explanation`,`cno`,`pName`)
VALUES
(1,'Student has a GPA < 2.0',1,'Computer Science');

INSERT INTO `jupyter`.`possiblescores`
(`score`,`explanation`,`cno`,`pName`)
VALUES
(2,'Student has a GPA is between 2.0 and 3.0',1,'Computer Science');

INSERT INTO `jupyter`.`possiblescores`
(`score`,`explanation`,`cno`,`pName`)
VALUES
(3,'Student has a GPA > 3.0',1,'Computer Science');

INSERT INTO `jupyter`.`possiblescores`
(`score`,`explanation`,`cno`,`pName`)
VALUES
(1,'Student has a BS in a field outside Life Science',2,'Chemistry');

INSERT INTO `jupyter`.`possiblescores`
(`score`,`explanation`,`cno`,`pName`)
VALUES
(2,'Student has a BS in Life Science outside of Chemistry',2,'Chemistry');

INSERT INTO `jupyter`.`possiblescores`
(`score`,`explanation`,`cno`,`pName`)
VALUES
(3,'Student has a BS in Chemistry',2,'Chemistry');

# Create Program Requirements
INSERT INTO `jupyter`.`reqt`
(`question`,`pName`)
VALUES
('What is your favorite coding language?','Computer Science');

INSERT INTO `jupyter`.`reqt`
(`question`,`pName`)
VALUES
('How many coding languages do you know?','Computer Science');

INSERT INTO `jupyter`.`reqt`
(`question`,`pName`)
VALUES
('Which chemistry do your prefer: Organic or inorganic?','Chemistry');

INSERT INTO `jupyter`.`reqt`
(`question`,`pName`)
VALUES
('How many chemistry classes have you taken?','Chemistry');

# Possible Answer
INSERT INTO `jupyter`.`possibleanswers`
(`answer`,`qno`,`pName`)
VALUES
('Python', 1, 'Computer Science');

INSERT INTO `jupyter`.`possibleanswers`
(`answer`,`qno`,`pName`)
VALUES
('C++', 1, 'Computer Science');

INSERT INTO `jupyter`.`possibleanswers`
(`answer`,`qno`,`pName`)
VALUES
('Java', 1, 'Computer Science');

INSERT INTO `jupyter`.`possibleanswers`
(`answer`,`qno`,`pName`)
VALUES
('<2', 2, 'Computer Science');

INSERT INTO `jupyter`.`possibleanswers`
(`answer`,`qno`,`pName`)
VALUES
('between 2 and 4', 2, 'Computer Science');

INSERT INTO `jupyter`.`possibleanswers`
(`answer`,`qno`,`pName`)
VALUES
('>4', 2, 'Computer Science');

INSERT INTO `jupyter`.`possibleanswers`
(`answer`,`qno`,`pName`)
VALUES
('Organic', 3, 'Chemistry');

INSERT INTO `jupyter`.`possibleanswers`
(`answer`,`qno`,`pName`)
VALUES 
('Inorganic', 3, 'Chemistry');

INSERT INTO `jupyter`.`possibleanswers`
(`answer`,`qno`,`pName`)
VALUES
('<3', 4, 'Chemistry');

INSERT INTO `jupyter`.`possibleanswers`
(`answer`,`qno`,`pName`)
VALUES
('between 3 and 6', 4, 'Chemistry');

INSERT INTO `jupyter`.`possibleanswers`
(`answer`,`qno`,`pName`)
VALUES
('>6', 4, 'Chemistry');

# Evaluations
INSERT INTO `jupyter`.`evaluation`
(`faculty`, `completionDate`,`decision`,`aid`)
VALUES
(1, '2016-08-30 19:05:00', 'No', 1);

INSERT INTO `jupyter`.`evaluation`
(`faculty`, `completionDate`,`decision`,`aid`)
VALUES
(1, '2016-08-15 19:05:00', 'Yes', 2);

INSERT INTO `jupyter`.`evaluation`
(`faculty`, `completionDate`,`decision`,`aid`)
VALUES
(2, '2016-08-27 19:05:00', 'Yes', 3);

INSERT INTO `jupyter`.`evaluation`
(`faculty`, `completionDate`,`decision`,`aid`)
VALUES
(2, '2016-09-30 19:05:00', 'Yes', 4);

INSERT INTO `jupyter`.`gre`
(`testDate`,`QuantScore`,`VerbalScore`,`AnalyticalScore`,`aid`)
VALUES
(date '2016-05-30', 138, 154, 2.5, 1);

INSERT INTO `jupyter`.`gre`
(`testDate`,`QuantScore`,`VerbalScore`,`AnalyticalScore`,`aid`)
VALUES
(date '2016-05-30', 138, 154, 2.5, 2);

INSERT INTO `jupyter`.`gre`
(`testDate`,`QuantScore`,`VerbalScore`,`AnalyticalScore`,`aid`)
VALUES
(date '2016-05-30', 165, 150, 5, 3);

INSERT INTO `jupyter`.`gre`
(`testDate`,`QuantScore`,`VerbalScore`,`AnalyticalScore`,`aid`)
VALUES
(date '2016-05-30', 165, 150, 5, 4);

INSERT INTO `jupyter`.`gre`
(`testDate`,`QuantScore`,`VerbalScore`,`AnalyticalScore`,`aid`)
VALUES
(date '2016-05-30', 160, 160, 4.5, 5);

INSERT INTO `jupyter`.`gre`
(`testDate`,`QuantScore`,`VerbalScore`,`AnalyticalScore`,`aid`)
VALUES
(date '2016-05-30', 160, 160, 4.5, 6);

# Letters of Ref
INSERT INTO `jupyter`.`lettersofref`
(`refName`,`refEmail`,`aid`)
VALUES
('Dr. A', 'drA@domain.edu', 1);

INSERT INTO `jupyter`.`lettersofref`
(`refName`,`refEmail`,`aid`)
VALUES
('Dr. A', 'drA@domain.edu', 2);

INSERT INTO `jupyter`.`lettersofref`
(`refName`,`refEmail`,`aid`)
VALUES
('Dr. B', 'drB@domain.edu', 3);

INSERT INTO `jupyter`.`lettersofref`
(`refName`,`refEmail`,`aid`)
VALUES
('Dr. B', 'drB@domain.edu', 4);

INSERT INTO `jupyter`.`lettersofref`
(`refName`,`refEmail`,`aid`)
VALUES
('Dr. A', 'drA@domain.edu', 5);

INSERT INTO `jupyter`.`lettersofref`
(`refName`,`refEmail`,`aid`)
VALUES
('Dr. A', 'drA@domain.edu', 6);





# Update 
UPDATE `jupyter`.`application`
SET `startYear` = 2019
WHERE `aid` = 2;

UPDATE `jupyter`.`applicant`
SET `email` = 'bricha2@umbc.edu'
WHERE `pid` = 1;

UPDATE `jupyter`.`evaluation`
SET `completionDate` = current_timestamp
WHERE `faculty` = 2 AND `aid` = 3;

UPDATE `jupyter`.`program`
SET `phone` = 3013050668
WHERE `pName` = 'Computer Science';

UPDATE `jupyter`.`reqt`
SET `question` = 'How many coding languages are you an expert of?'
WHERE `qno` = 2 AND `pName` = 'Computer Science';

UPDATE `jupyter`.`rubric`
SET `criteria` = 'GRE'
WHERE `cno` = 1 AND `pName` = 'Computer Science';

UPDATE `jupyter`.`possibleanswers`
SET `answer` = 'C++/C/C#' 
WHERE `answer` = 'C++' AND `qno` = 2 AND `pName` = 'Computer Science';

UPDATE `jupyter`.`possiblescores`
SET `explanation` = 'Does not have a BS'
WHERE `score` = 1 AND `cno` = 4 AND `pName` = 'Chemistry';



