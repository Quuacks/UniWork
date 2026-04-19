#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	char name[30];
	char surname[30];
	int course;					// year of study
	double average; 			// average grade
	
	int load; 					// number of courses
	char courses[10][30]; 		// course names
	int grades[10]; 			// course grades	
	
	char languages[100];		// spoken languages
	
} Student;


int main(int argc, char *argv[]) {
	FILE *db = NULL;
	FILE *report = fopen("report.txt","a");;
	// open database file for reading, provide a parameter or use default "db.bin"
	if (argc > 1)
		db = fopen(argv[1], "rb");
	else
		db = fopen("db.bin", "rb");
		
	if (db){							
		Student students[1000];		// all the data goes here
		int studentIndexes[4] = {-1};
		int size = 0;					// how many students in database
		
		// reading data from file
		fread(&size, sizeof(int), 1, db);
		
		for (int i = 0; i < size; i++){			
			fread(&students[i], sizeof(Student), 1, db);			
		}	
		printf("%d records loaded succesfully\n", size);
		
		
		// MODIFY CODE BELOW
		fprintf(report, "QUERY3\n");
		int counterDemo = 0; // for counting students
		
		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i]; // store data for each student in s
			
			if(s.name[0] != 'A' && s.name[0] != 'E' && s.name[0] != 'I' && s.name[0] != 'U' && s.name[0] != 'O' && s.name[0] != 'Y'){ // *** first filter, conditions on the student
				if(counterDemo < 4)
					studentIndexes[counterDemo] = i;
				 // print student data
				int anotherDemo = 0; // for counting courses/grades
				fprintf(report,"");
				for (int i = 0; i < s.load; ++i){ // process each course taken by the student
					if(1){ // *** second filter, conditions on the course/grade
						++anotherDemo; // counting courses
						//fprintf(report,"%s: %d   ", s.courses[i], s.grades[i]);
					}
				}
						
				if (anotherDemo == s.load) // *** third filter, various other conditions			
					++counterDemo; // counting students
			}
		}
		fprintf(report, "%d", counterDemo);
		for(int i = 0; i < 3; ++i){
			if(studentIndexes[i] == -1)
				continue;
			Student s = students[studentIndexes[i]];
			fprintf(report, "\nVardas Pavarde: %s %s Kursas: %d Vidurkis: %.2f Kursai: %d ", s.name, s.surname, s.course, s.average, s.load);
			for (int j = 0; j < s.load; ++j){
					fprintf(report,"%s: %d   ", s.courses[i], s.grades[i]);
				}
			fprintf(report, "Mokamos Kalbos: %s", s.languages);
		}
		if(studentIndexes[3] != -1)
			fprintf(report,"\n...\n");
		printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
		fclose(db);	
	} else {
		printf("File db.bin not found, check current folder\n");
	}
	fclose(report);
	return 0;
}