use `jupyter`;

# 1. List the names of all applicants for a given degree program and period (semester/year).
SELECT `applicant`.`fname`
FROM `application`, `applicant`
WHERE `applicant`.`pid` = `application`.`pid` and `application`.`pname` = 'Chemistry' and 
	`application`.`semester` = 'Spring' and `application`.`startyear` = 2018;

# 2. Find the total number of applicants by program and period.
SELECT `application`.`pname`, COUNT(DISTINCT `pid`)
FROM `program`, `application`
GROUP BY `application`.`pname`;

# 3. Find the most “popular” major among the applicants in a given year.
SELECT `prioreducation`.`major`, count(`prioreducation`.`major`) as frequency#, `application`.`pName`
FROM `prioreducation`, `application`, `applicant`
WHERE `prioreducation`.`aid` = `application`.`aid` and `application`.`pid` = `applicant`.`pid` and `application`.`startYear` = 2018
GROUP BY `prioreducation`.`major`
ORDER BY frequency DESC
LIMIT 1;

# 4. Find those applicants with the lowest GPA that have been admitted in the current period.
SELECT `applicant`.`pid`,`priorEducation`.`gpa`
FROM `application`, `evaluation`, `priorEducation`, `applicant`
WHERE `applicant`.`pid` = `application`.`pid` and `application`.`aid` = `evaluation`.`aid` and `application`.`aid` = `priorEducation`.`aid` and `evaluation`.`decision` = 'Yes'
ORDER BY `priorEducation`.`gpa`
LIMIT 1;

# 5. Find the number of students applying to a degree program, for each degree program by prior degree.
SELECT `application`.`pname`, `priorEducation`.`degree`, count(`application`.`aid`)
FROM `application`,`applicant`, `priorEducation`
WHERE `prioreducation`.`aid`= `application`.`aid` and `application`.`pid` = `applicant`.`pid` and `application`.`pname` = 'Computer Science'
GROUP BY `priorEducation`.`degree`, `application`.`pname`; 

# 6. Find the applications that have not been evaluated by anyone till a certain date.
# ADD TO PYTHON
SELECT a.`aid`
FROM `application` as a
WHERE a.`aid` NOT IN
	(SELECT b.`aid`
	FROM `application` as b,`evaluation`
	WHERE b.`aid` = `evaluation`.`aid` and `evaluation`.`completionDate` < date '2016-08-31'
	ORDER BY `evaluation`.`completionDate`);

# 7. Find the number of applications submitted/accepted/denied by program and year
-- #SELECT `application`.`pname`, 
-- #FROM `application`, `evaluation`
-- #WHERE `application`.`aid` = `evaluation`.`aid`
-- #GROUP BY `application`.`pname`;

# 8. Find the emails of those references that resulted in the most acceptance decisions.
# ADD TO PYTHON
SELECT `lettersofref`.`refEmail`, count(`evaluation`.`decision`) as acceptances
FROM `lettersofref`,`application`, `evaluation`
WHERE `lettersofref`.`aid` = `application`.`aid` and `application`.`aid` = `evaluation`.`aid` and `evaluation`.`decision` = 'Yes'
GROUP BY `lettersofref`.`refEmail`
ORDER BY acceptances DESC
LIMIT 5;


# 9. Find the minimum, maximum, average, and standard deviation of the GRE scores of the applicants, by program and application year.
select `application`.`pname`, min(`gre`.`QuantScore`), min(`gre`.`VerbalScore`), min(`gre`.`AnalyticalScore`),
							max(`gre`.`QuantScore`), max(`gre`.`VerbalScore`), max(`gre`.`AnalyticalScore`),
                            avg(`gre`.`QuantScore`), avg(`gre`.`VerbalScore`), avg(`gre`.`AnalyticalScore`),
							stddev(`gre`.`QuantScore`), stddev(`gre`.`VerbalScore`), stddev(`gre`.`AnalyticalScore`)
FROM `application`, `gre`
WHERE `application`.`aid` = `gre`.`aid`
Group by `application`.`pname`;
-- 

# 10. Find the college(s) attended by most applicants over the last 5 years.
# ADD TO PYTHON
SELECT `prioreducation`.`university`, count(`prioreducation`.`aid`) as freq
FROM `prioreducation`
WHERE `prioreducation`.`gradDate` > date_sub(now(), interval 5 year)
GROUP BY `prioreducation`.`university`
ORDER BY freq DESC
LIMIT 1;