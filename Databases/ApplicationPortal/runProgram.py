#!/usr/bin/python

hostname = 'localhost'
username = 'root'
password = ''
database = 'jupyter'

import pymysql

def doQuery(conn):
    curr = conn.cursor()
    curr.execute("")


def QueryOne(conn, startyear, pName):
    curr = conn.cursor()
    curr.execute("SELECT `applicant`.`fname` FROM `application`, `applicant` "
                "WHERE `applicant`.`pid` = `application`.`pid` and `application`.`pname` = '"+ pName+"' and "
                "`application`.`semester` = 'Spring' and `application`.`startyear` = " + startyear + ";")
    for fname in curr.fetchall():
        print(fname)

def QueryTwo(conn):
    curr = conn.cursor()
    curr.execute("SELECT `application`.`pname`, COUNT(DISTINCT `pid`)"
                 "FROM `program`, `application` GROUP BY `application`.`pname`;")
    for pname,count in curr.fetchall():
        print(pname, count)

def QueryThree(conn, startyear):
    curr = conn.cursor()
    curr.execute("SELECT `prioreducation`.`major`, count(`prioreducation`.`major`) AS frequency "
                 "FROM `prioreducation`, `application`, `applicant` "
                 "WHERE `prioreducation`.`aid` = `application`.`aid` and `application`.`pid` = `applicant`.`pid` and `application`.`startYear` = "  + startyear + " "
                 "GROUP BY `prioreducation`.`major` "
                 "ORDER BY frequency DESC LIMIT 1;")
    for major,count in curr.fetchall():
        print(major, count)

def QueryFour(conn):
    curr = conn.cursor()
    curr.execute("SELECT `applicant`.`pid`,`priorEducation`.`gpa` "
                 "FROM `application`, `evaluation`, `priorEducation`, `applicant`"
                 "WHERE `applicant`.`pid` = `application`.`pid` and `application`.`aid` = `evaluation`.`aid` and `application`.`aid` = `priorEducation`.`aid` and `evaluation`.`decision` = 'Yes'"
                 "ORDER BY `priorEducation`.`gpa`"
                 "LIMIT 1;")
    for pid,gpa in curr.fetchall():
        print(pid, gpa)

def QueryFive(conn, pName):
    curr = conn.cursor()
    curr.execute("SELECT `application`.`pname`, `priorEducation`.`degree`, count(`application`.`aid`)"
                 "FROM `application`,`applicant`, `priorEducation`"
                 "WHERE `prioreducation`.`aid`= `application`.`aid` and `application`.`pid` = `applicant`.`pid` and `application`.`pname` = '"+pName+"'"
                 "GROUP BY `priorEducation`.`degree`, `application`.`pname`;")
    for pname,degree, count in curr.fetchall():
        print(pname, degree, count)

def QuerySix(conn):
    curr = conn.cursor()
    curr.execute("SELECT a.`aid`"
                 "FROM `application` as a "
                 "WHERE a.`aid` NOT IN "
                 "(SELECT b.`aid` FROM `application` as b,`evaluation` "
                 "WHERE b.`aid` = `evaluation`.`aid` and `evaluation`.`completionDate` < date '2016-08-31' "
                 "ORDER BY `evaluation`.`completionDate`);")
    for aid in curr.fetchall():
        print(aid)

def QuerySeven(conn):
    curr = conn.cursor()
    curr.execute("")
    for aid in curr.fetchall():
        print(aid)

def QueryEight(conn):
    curr = conn.cursor()
    curr.execute("SELECT `lettersofref`.`refEmail`, count(`evaluation`.`decision`) as acceptances "
                 "FROM `lettersofref`,`application`, `evaluation` "
                 "WHERE `lettersofref`.`aid` = `application`.`aid` and `application`.`aid` = `evaluation`.`aid` and `evaluation`.`decision` = 'Yes' "
                 "GROUP BY `lettersofref`.`refEmail` ORDER BY acceptances DESC LIMIT 5;")
    for emails, count in curr.fetchall():
        print(emails, count)

def QueryNine(conn):
    curr = conn.cursor()
    curr.execute("select `application`.`pname`, min(`gre`.`QuantScore`), min(`gre`.`VerbalScore`), min(`gre`.`AnalyticalScore`),"
                 "max(`gre`.`QuantScore`), max(`gre`.`VerbalScore`), max(`gre`.`AnalyticalScore`),"
                 "avg(`gre`.`QuantScore`), avg(`gre`.`VerbalScore`), avg(`gre`.`AnalyticalScore`),"
                 "stddev(`gre`.`QuantScore`), stddev(`gre`.`VerbalScore`), stddev(`gre`.`AnalyticalScore`)"
                 "FROM `application`, `gre`"
                 "WHERE `application`.`aid` = `gre`.`aid`"
                 "Group by `application`.`pname`;")
    for pname,minQ, minV, minA, maxQ, maxV, maxA, avgQ, avgV, avgA, stdQ, stdV, stdA in curr.fetchall():
        print(pname,minQ, minV, minA, maxQ, maxV, maxA, avgQ, avgV, avgA, stdQ, stdV, stdA)

def QueryTen(conn):
    curr = conn.cursor()
    curr.execute("SELECT `prioreducation`.`university`, count(`prioreducation`.`aid`) as freq "
                 "FROM `prioreducation` WHERE `prioreducation`.`gradDate` > date_sub(now(), interval 5 year) "
                 "GROUP BY `prioreducation`.`university` ORDER BY freq DESC LIMIT 1;")
    for university, count in curr.fetchall():
        print(university, count)

def main():
    myConnection = pymysql.connect(host=hostname, user=username, passwd=password, db=database)
    c = myConnection.cursor()
    print("Welcome to the Jupyter database! Let's explore a few previously requested queries!")

    # First prompt
    print("Query #1. List the names of all applicants for a given degree program and period (semester/year).")
    startYear = input("For Query 1, what year would you like to input?")
    pName = input("What program are you interested in?")
    print("Name of applicants:")
    QueryOne( myConnection, startYear, pName )

    #Second Prompt
    print("Query #2. Find the total number of applicants by program and period.")
    print("Program name and number:")
    QueryTwo( myConnection)

    #Third Prompt
    print("Query #3. Find the most “popular” major among the applicants in a given year.")
    startYear = input("For Query 3, what year would you like to input?")
    print("Major and count:")
    QueryThree( myConnection, startYear)

    # Fourth Prompt
    print("Query #4. Find those applicants with the lowest GPA that have been admitted in the current period.")
    print("Person ID and GPA")
    QueryFour( myConnection)

    # Fifth Prompt
    print("Query #5. Find the number of students applying to a degree program, for each degree program by prior degree.")
    print("Program Name, Prior Degree, and count:")
    pName = input("For Query 5, what program would you like to search? ")
    QueryFive( myConnection, pName )

    # Sixth Prompt
    print("Query #6. Find the applications that have not been evaluated by anyone till a certain date.")
    print("Application IDs:")
    QuerySix(myConnection)

    # Seventh Prompt
    print("Sorry Prompt 7 is out of operation. Come back to this one later!")
    QuerySeven( myConnection)

    # Eight Prompt
    print("Query #8. Find the emails of those references that resulted in the most acceptance decisions.")
    print("Email and number of acceptances")
    QueryEight( myConnection)

    # Nine Prompt
    print("Query #9. Find the minimum, maximum, average, and standard deviation of the GRE scores of the applicants, by program and application year.")
    print("Min, Max, Avg, and STDDEV for each group")
    QueryNine( myConnection)

    # Ten Prompt
    print("Query #10. Find the college(s) attended by most applicants over the last 5 years.")
    print("University & number of accepted applicants")
    QueryTen( myConnection)

    myConnection.close()

main()

 #   except OperationalError, msg:
  #      print "Command skipped: ", msg