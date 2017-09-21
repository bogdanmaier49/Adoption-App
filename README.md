The “Keep calm and adopt a pet” shelter needs a software application to help them find adoptive
parents for the dogs1
they are taking care of. The application can be used in two modes: administrator
and user. When the application is started, it will offer the option to choose the mode.


Administrator mode: The application will have a database2
, which holds all the dogs in the shelter at a
given moment. The shelter employees must be able to update the database, meaning: add a new dog,
delete a dog (when the dog is adopted) and update the information of a dog. Each Dog has a breed, a
name, an age and a photograph. The photograph is memorised as a link towards an online resource (the
photograph on the presentation site of the centre). The administrators will also have the option to see
all the dogs in the shelter.
User mode: A user can access the application and choose one or more dogs to adopt. The application
will allow the user to:
a. See the dogs in the database, one by one. When the user chooses this option, the data of the
first dog (breed, name, age) is displayed, along with its photograph.
b. Choose to adopt the dog, in which case the dog is added to the user’s adoption list.
c. Choose not to adopt the dog and to continue to the next. In this case, the information
corresponding to the next dog is shown and the user is again offered the possibility to adopt it.
This can continue as long as the user wants, as when arriving to the end of the list, if the user
chooses next, the application will again show the first dog.
d. See all the dogs of a given breed, having an age less than a given number. If the breed is empty,
then all the dogs will be considered. The same options (a, b and c) apply in this case.
e. See the adoption list.


1. Replace your DynamicVector template with the STL vector. Use STL algorithms wherever possible
in your application (e.g. in your filter function you could use copy_if, count_if). Replace all your
for loops either with STL algorithms, or with the ranged-based for loop (C++11).
2. Store your data in a text file. When the program starts, the entities in the database (file) will be
read. The modifications made during the execution of the application should be stored in the file.
For this feature, use the iostream library. Create insertion and extraction operators for your
entities and use these when reading/writing to files or console.
3. Use exceptions to signal errors:
- from the repository;
- validation errors – validate your entities using Validator classes;
- create your own exception classes.
Validate all your input data.
4. All the functions in your application must be specified and tested. Using the OpenCppCoverage
tool (http://www.cs.ubbcluj.ro/~iuliana/oop/Tutorials/Code_coverage.pdf), make sure you have
at least 99% coverage for all your modules, except for the UI. For Linux, you may use any
appropriate tool you find.
Observation: Points 5 and 6 should be solved using inheritance and polymorphism.
5. Depending on your assignment, store your:
- adoption list
- movie watch list
- shopping basket
- tutorial watch list
in a file. When the application starts, the user should choose the type of file (CSV or HTML).
Depending on this type, the application should save the list in the correct format.
Indications
- the CSV file will contain each entity on one line and the attributes will be separated by
comma (,)
E.g. (for Song entities):
Ed Sheeran,I see fire,4:54, https://www.youtube.com/watch?v=2fngvQS_PmQ
The Proclaimers,I would walk 500 miles,3:37,https://www.youtube.com/watch?v=otXGqU4LBEI
- in the HTML file you will have a table, in which each row holds the data of one entity. The
columns of the table will contain the names of the data attributes.
E.g. (for Song entities) – the text written in magenta offers comments (these do NOT belong
to the html file).
<!DOCTYPE html> - write this exactly as it is here
<html> - write this exactly as it is here
<head> - write this exactly as it is here
<title>Playlist</title> - replace “Playlist” with the title for your HTML
</head> - write this exactly as it is here (close head tag)
<body> - write this exactly as it is here
<table border="1"> - write this exactly as it is here
 <tr> - tr = table row; 1 row for each entity
<td>Artist</td> - td = table data; 1 td for each attribute of the entity
<td>Title</td>
<td>Duration</td>
<td>Youtube link</td>
 </tr> - write this exactly as it is here (close tr tag)
 <tr>
<td>Ed Sheeran</td>
<td>I see fire</td>
<td>4:54</td>
<td><a href =
"https://www.youtube.com/watch?v=2fngvQS_PmQ">Link</a></td>
- a href makes the text “Link” clickable and directs us towards the link written after “=”
 </tr>
 <tr>
<td>The Proclaimers</td>
<td>I would walk 500 miles</td>
<td>3:37</td>
<td><a href =
"https://www.youtube.com/watch?v=otXGqU4LBEI">Link</a></td>
 </tr> - write this exactly as it is here (close tr tag)
</table> - write this exactly as it is here (close table tag)
</body> - write this exactly as it is here (close body tag)
</html> - write this exactly as it is here (close html tag)
The file above, if opened with a browser, looks like this:
6. Add a new command, allowing the user to see the:
- adoption list
- movie watch list
- shopping basket
- tutorial watch list
Displaying the list means opening the saved file (csv or html) with the correct application:
- CSV file – with Notepad, Notepad++, Microsoft Excel or OpenOffice Calc
- HTML file – with a browser
7. Create a UML diagram for your entire application. For this, you can use any tool that you like
(StarUML is an example of open source software for UML). Do not draw the diagram by hand.
