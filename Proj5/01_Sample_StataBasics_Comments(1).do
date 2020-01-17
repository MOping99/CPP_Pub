clear all  
//This line clears all memory and settings from Stata so that you don't get any unexpected errors due to previously run, but currently unneeded, code.
set more off, perm 
//This line turns off Stata's "more" feature, which prevents Stata from showing the entire results of a command if the results take up too much space.
version 13 
//This line tells Stata which version the code was written with. Newer versions will run code written with older versions, but the reverse is not true.

cd "D:\1920_Sem2_Econ300\Stata_Tutorial_01"
//This line changes the working directory. I have it set to the folder in which I stored the data for the first tutorial video.

local date: display %td_YY_NN_DD date(c(current_date), "DMY")
local today = subinstr(trim("`date'"), " " , "", .)
//These lines create a macro which automatically generates the current date in YYMMDD format. This is incredibly helpful for keeping logs, figures, and tables organized.

log using "`today'_Sample_StataBasics.log", text append
//This line creates a log file. The "text" option tells Stata to save the file as a text file, rather than using Stata's mark-up language. The "append" option means that if you run the do-file multiple times, it will not delete the log from the previous run-through, but will add it to the end.

/*
File name: 		01_Sample_StataBasics.do
Input:			ACS_2005-2016.dta
Output:			ACS_Clean.dta

Created By: 	Jaselyn Taubel
Date Created:	01/13/2019
Date Updated:	01/13/2019

Description:
This do-file imports the ACS sample data from 2005-2016. It summarizes important details of the data, cleans it, and then runs a simple analysis.

Data Citation: Ruggles, Steven, Sarah Flood, Ronald Goeken, Josiah Grover, Erin Meyer, Jose Pacas, and Matthew Sobek. 2018. Integrated Public Use Microdata Series: Version 8.0 [dataset]. University of Minnesota, Minneapolis, MN. doi:https://doi.org/10.18128/D010.V8.0.
*/

//I always begin my do-files with this block of commenting. It helps me to keep organized and to remember what the purpose of the file is. It also helps if, in the middle of a project, I need to change a dataset, but can't remember where I last worked with it. A quick glance at the Input/Output line can help me to remember which files each do-file works with. You should also always cite the data source in your do-files.

use "ACS_2005-2016.dta", clear 
//This line opens my .dta file. The "clear" option tells Stata to close any datasets that are already open. It is redundant with the "clear all" command at the beginning of th file, but it is always a good idea to include anyway.

***Summarize Data***
display _N
//This tells me how many total observations are in my dataset.

tab year
tab gq
tab race
tab educ
tab sex

summ age
summ inctot
summ incearn
summ poverty
//These lines give me basic information on some of the main variables in my dataset. I could also have stata perform these actions by writing a loop, as in the next few lines.

foreach var in year gq race educ sex {
	display " " //This helps with making sure the output is readable
	display "`var'"
	tab `var'
}

foreach var in age inctot incearn poverty {
	display " "
	display "`var'"
	summ `var'
}
//These "foreach" loops execute the exact same commands as the individual lines of code written above. In your own code, you are welcome to write loops if you are comfortable, but you are not required to do so.

***Clean Data***
drop if educ < 6
drop if !(gq == 1 | gq == 2 | gq == 5)
*Keep only those with at least a 12th grade education.
*Keep only those who are identified as living in a household.
//These two lines are cleaning my data. They are dropping observations that are not useful for my analysis. Note that both commands use "if" qualifiers followed by Boolean statements. You may find a list of Stata's Boolean operators on Blackboard.

***Analysis***
reg inctot i.educ
reg incearn i.educ
*Analyze relationship between income and educational attainment

reg inctot i.educ age
reg incearn i.educ age
*Control for effect of age on both educational attainment and earnings.

***Save Data***
save "ACS_Clean.dta", replace
//The replace command tells Stata that, if there is another dataset with the same name, it should overwrite that dataset with this one.

log close
//This command closes and saves the log file.
