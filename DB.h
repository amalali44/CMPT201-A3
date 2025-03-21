/* DB.h
 * 
 * Public interface to the specification for your database implementation
 *
 * Please do not modify any code in this file!  We will be testing your code
 * under the assumption that the public interface matches this interface.
 *
 * Author: Ali, Ardon, Kevin
 * Lab instructor: Dara Wagh
 * Lecture instructor: Abdullah Mohiuddin  
 */


#ifndef DB_H
#define DB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/*
 * The INIT_SIZE is only relevant if you are using arrays for your data structures. 
 * If you are using linked lists you will not need it
 */

#define INIT_SIZE 5

/*
 * DECLARE AND TYPEDEF HERE THE STRUCTS Table, NeighbourhoodTable, AND PicnicTable
 * WHICH WILL BE FIELDS IN THE STRUCT DataBase BELOW. YOU MAY DECLARE ADDITIONAL
 * STRUCTS AS NEEDED.
 */

typedef struct Table {
    int code;
    char* value;
} Table;

typedef struct NeighbourhoodTable {
    int neighbourhoodID;
    char* neighbourhoodName;
    int ward;
} NeighbourhoodTable;

typedef struct PicnicTable {
    int tableID;
    char* tabletype;
    char* surfaceMaterial;
    char* structuralMaterial;
    char* streetAvenue;
    int neighbourhoodID;
    char* neighbourhoodName;
    char* ward;
    char* latitude;
    char* longitude;
} PicnicTable;

/*
 * You may change the internal details of the struct below,
 * only keep it typedef'ed to DataBase
 */

typedef struct {
    Table *tableTypeTable;
    Table *surfaceMaterialTable;
    Table *structuralMaterialTable;
    NeighbourhoodTable *neighborhoodTable;
    PicnicTable *picnicTableTable;
    int tableTypeCount;
    int surfaceMaterialCount;
    int structuralMaterialCount;
    int neighbourhoodCount;
    int picnicTableCount;
} DataBase;

/* Declare a global DataBase variable*/
/* That should be the only global variable declared*/
/* DB.c should have the definition of this variable*/

extern DataBase *Db;

int importDB(const char* filename); // "implement an application that can read a data file in .csv format and create a Database"
int exportDB(const char* filename); // "this function takes the name of a .csv file as parameter and creates a .csv file containing the information of the Database. NOTE: the exported .csv file must be exactly the same as the original .csv file from which the Database was created."
void initializeDB(void); // ""Your program should not allow any operation to be performed on the Database, until the database is created"

/*
 * Take the name of a member of the picnicTable entry and a value for that member 
 * as parameters and return the number of entries in the picnicTable which have 
 * that value for the memberName.
 * 
 * This is to be implemented for the following members:
 *  1- Table Type
 *  2- Surface Material
 *  3- Structural Material
 *  4- Neighborhood ID
 *  5- Neighborhood Name
 *  6- Ward
 */
int countEntries(char *memberName, char *value);

/*
 * Take the name of a member of the picnicTable entry as an argument 
 * and sort the table in ascending order of the entry values of that member. 
 * The function must be implemented for:
 *   1- Table Type
 *   2- Surface Material
 *   3- Structural Material
 *   4- Neighborhood Name
 *   5- Ward
 */

void sortByMember(char *memberName);

/*
 * Take a tableID, the name of a member of the picnicTable entry and a value for that 
 * member as parameters, and find the entry which has that tableID and 
 * change its memberName value to newValue. 
 * Members that can be modified:
 *  1- Table Type
 *  2- Surface Material
 *  3- Structural Material 
 * If the new value is not found in the existing tables, this value must be added to the 
 * corresponding table.
 */

void editTableEntry(int tableID, char *memberName, char *value);

/*
 * print a listing of picnic tables grouped by neigbourhoods in ascending 
 * alphabetical order.
 */

void reportByNeighbourhood(void);

/*
 * print a listing of picnic tables grouped by wards in ascending order.
 */

void reportByWard(void);

/*
 * Frees all dynamic memory associated with each table upon exit. 
 */

void freeDB();

#endif
