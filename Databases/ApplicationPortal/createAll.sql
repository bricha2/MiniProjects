-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema jupyter
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema jupyter
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `jupyter` DEFAULT CHARACTER SET utf8 ;
USE `jupyter` ;

-- -----------------------------------------------------
-- Table `jupyter`.`Applicant`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `jupyter`.`Applicant` (
  `pid` INT NOT NULL AUTO_INCREMENT,
  `gender` ENUM('Male', 'Female') NULL,
  `DOB` DATE NULL,
  `fName` VARCHAR(45) NULL,
  `mInitial` VARCHAR(45) NULL,
  `lName` VARCHAR(45) NULL,
  `email` VARCHAR(45) NULL,
  `street` VARCHAR(45) NULL,
  `city` VARCHAR(45) NULL,
  `state` VARCHAR(45) NULL,
  `zipcode` INT NULL,
  PRIMARY KEY (`pid`),
  UNIQUE INDEX `pid_UNIQUE` (`pid` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `jupyter`.`applicantPhone`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `jupyter`.`applicantPhone` (
  `phoneNumber` INT NOT NULL,
  `pid` INT NOT NULL,
  PRIMARY KEY (`phoneNumber`, `pid`),
  INDEX `fk_applicantPhone_Applicant_idx` (`pid` ASC),
  CONSTRAINT `fk_applicantPhone_Applicant`
    FOREIGN KEY (`pid`)
    REFERENCES `jupyter`.`Applicant` (`pid`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `jupyter`.`Program`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `jupyter`.`Program` (
  `pName` VARCHAR(45) NOT NULL,
  `dept` VARCHAR(45) NULL,
  `phone` VARCHAR(20) NULL,
  PRIMARY KEY (`pName`),
  UNIQUE INDEX `pName_UNIQUE` (`pName` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `jupyter`.`Application`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `jupyter`.`Application` (
  `aid` INT NOT NULL AUTO_INCREMENT,
  `semester` VARCHAR(45) BINARY NULL,
  `startYear` YEAR NULL,
  `SOP` BLOB NULL,
  `pid` INT NOT NULL,
  `pName` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`aid`),
  UNIQUE INDEX `aid_UNIQUE` (`aid` ASC),
  INDEX `fk_Application_Applicant1_idx` (`pid` ASC),
  INDEX `fk_Application_Program1_idx` (`pName` ASC),
  CONSTRAINT `fk_Application_Applicant1`
    FOREIGN KEY (`pid`)
    REFERENCES `jupyter`.`Applicant` (`pid`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_Application_Program1`
    FOREIGN KEY (`pName`)
    REFERENCES `jupyter`.`Program` (`pName`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `jupyter`.`GRE`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `jupyter`.`GRE` (
  `testDate` DATE NOT NULL,
  `QuantScore` INT NULL,
  `VerbalScore` INT NULL,
  `AnalyticalScore` INT NULL,
  `aid` INT NOT NULL,
  PRIMARY KEY (`testDate`, `aid`),
  INDEX `fk_GRE_Application1_idx` (`aid` ASC),
  CONSTRAINT `fk_GRE_Application1`
    FOREIGN KEY (`aid`)
    REFERENCES `jupyter`.`Application` (`aid`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `jupyter`.`priorEducation`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `jupyter`.`priorEducation` (
  `university` VARCHAR(45) NOT NULL,
  `major` VARCHAR(45) NOT NULL,
  `degree` ENUM('BS', 'MS', 'PhD', 'BA', 'MA') NOT NULL,
  `gradDate` DATE NULL,
  `gpa` INT NULL,
  `aid` INT NOT NULL,
  PRIMARY KEY (`university`, `major`,`degree`,`aid`),
  INDEX `fk_priorEducation_Application1_idx` (`aid` ASC),
  CONSTRAINT `fk_priorEducation_Application1`
    FOREIGN KEY (`aid`)
    REFERENCES `jupyter`.`Application` (`aid`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `jupyter`.`lettersOfRef`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `jupyter`.`lettersOfRef` (
  `refName` VARCHAR(45) NOT NULL,
  `refEmail` VARCHAR(45) NULL,
  `aid` INT NOT NULL,
  PRIMARY KEY (`refName`, `aid`),
  INDEX `fk_lettersOfRef_Application1_idx` (`aid` ASC),
  CONSTRAINT `fk_lettersOfRef_Application1`
    FOREIGN KEY (`aid`)
    REFERENCES `jupyter`.`Application` (`aid`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `jupyter`.`Rubric`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `jupyter`.`Rubric` (
  `cno` INT NOT NULL AUTO_INCREMENT,
  `criteria` VARCHAR(45) NULL,
  `pName` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`cno`, `pName`),
  INDEX `fk_Rubric_Program1_idx` (`pName` ASC),
  CONSTRAINT `fk_Rubric_Program1`
    FOREIGN KEY (`pName`)
    REFERENCES `jupyter`.`Program` (`pName`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `jupyter`.`possibleScores`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `jupyter`.`possibleScores` (
  `score` INT NOT NULL,
  `explanation` VARCHAR(60) NULL,
  `cno` INT NOT NULL,
  `pName` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`score`, `cno`, `pName`),
  INDEX `fk_possibleScores_Rubric1_idx` (`cno` ASC, `pName` ASC),
  CONSTRAINT `fk_possibleScores_Rubric1`
    FOREIGN KEY (`cno` , `pName`)
    REFERENCES `jupyter`.`Rubric` (`cno` , `pName`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `jupyter`.`Reqt`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `jupyter`.`Reqt` (
  `qno` INT NOT NULL AUTO_INCREMENT,
  `question` VARCHAR(60) NULL,
  `pName` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`qno`, `pName`),
  INDEX `fk_Reqt_Program1_idx` (`pName` ASC),
  CONSTRAINT `fk_Reqt_Program1`
    FOREIGN KEY (`pName`)
    REFERENCES `jupyter`.`Program` (`pName`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `jupyter`.`satisfies`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `jupyter`.`satisfies` (
  `answer` BLOB NULL,
  `aid` INT NOT NULL,
  `qno` INT NOT NULL,
  `pName` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`aid`, `qno`, `pName`),
  INDEX `fk_satisfies_Application1_idx` (`aid` ASC),
  INDEX `fk_satisfies_Reqt1_idx` (`qno` ASC, `pName` ASC),
  CONSTRAINT `fk_satisfies_Application1`
    FOREIGN KEY (`aid`)
    REFERENCES `jupyter`.`Application` (`aid`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_satisfies_Reqt1`
    FOREIGN KEY (`qno` , `pName`)
    REFERENCES `jupyter`.`Reqt` (`qno` , `pName`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `jupyter`.`possibleAnswers`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `jupyter`.`possibleAnswers` (
  `answer` VARCHAR(45) NOT NULL,
  `qno` INT NOT NULL,
  `pName` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`answer`, `qno`, `pName`),
  INDEX `fk_possibleAnswers_Reqt1_idx` (`qno` ASC, `pName` ASC),
  CONSTRAINT `fk_possibleAnswers_Reqt1`
    FOREIGN KEY (`qno` , `pName`)
    REFERENCES `jupyter`.`Reqt` (`qno` , `pName`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `jupyter`.`Evaluation`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `jupyter`.`Evaluation` (
  `faculty` INT NOT NULL,
  `completionDate` DATETIME NULL,
  `decision` ENUM('Yes', 'No') NULL,
  `aid` INT NOT NULL,
  PRIMARY KEY (`faculty`, `aid`),
  INDEX `fk_Evaluation_Application1_idx` (`aid` ASC),
  CONSTRAINT `fk_Evaluation_Application1`
    FOREIGN KEY (`aid`)
    REFERENCES `jupyter`.`Application` (`aid`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `jupyter`.`Scores`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `jupyter`.`Scores` (
  `faculty` INT NOT NULL,
  `aid` INT NOT NULL,
  `cno` INT NOT NULL,
  `pName` VARCHAR(45) NOT NULL,
  `score` INT NULL,
  PRIMARY KEY (`faculty`, `aid`, `cno`, `pName`),
  INDEX `fk_Scores_Evaluation1_idx` (`faculty` ASC, `aid` ASC),
  INDEX `fk_Scores_Rubric1_idx` (`cno` ASC, `pName` ASC),
  CONSTRAINT `fk_Scores_Evaluation1`
    FOREIGN KEY (`faculty` , `aid`)
    REFERENCES `jupyter`.`Evaluation` (`faculty` , `aid`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_Scores_Rubric1`
    FOREIGN KEY (`cno` , `pName`)
    REFERENCES `jupyter`.`Rubric` (`cno` , `pName`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


#SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
