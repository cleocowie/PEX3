/** pex3functs.h
 * ===========================================================
 * Name: C3C Cleo Cowie, 26 Oct 2020
 * Section: T1/2
 * Project: PEX3
 * Purpose: File I/O, structs, string manipulation
 * ===========================================================
 */

#ifndef PEX3FUNCTS_H
#define PEX3FUNCTS_H

typedef struct DNA_struct {
    char species[20];
    char dna[500];
} DNA;

/** ----------------------------------------------------------
 * readFile() - reads in DNA sequences from a text file 
 * and stores them in an array of structs
 * @param fileName is the file being read
 * @param sequences array of DNA structures
 * @return the number of DNA sequences read from the file
 * ----------------------------------------------------------
 */
int readFile(char fileName[], DNA sequences[]);

/** ----------------------------------------------------------
 * readFile() - reads in DNA sequences from a text file 
 * and stores them in an array of structs
 * @param fileName is the file being read
 * @param sequences array of DNA structures
 * @return the number of DNA sequences read from the file
 * ----------------------------------------------------------
 */
void printSequences(DNA sequences[],int numSeq);

/** ----------------------------------------------------------
 * readFile() - reads in DNA sequences from a text file 
 * and stores them in an array of structs
 * @param fileName is the file being read
 * @param sequences array of DNA structures
 * @return the number of DNA sequences read from the file
 * ----------------------------------------------------------
 */
int hammingDistance(char str1[],char str2[]);

/** ----------------------------------------------------------
 * readFile() - reads in DNA sequences from a text file 
 * and stores them in an array of structs
 * @param fileName is the file being read
 * @param sequences array of DNA structures
 * @return the number of DNA sequences read from the file
 * ----------------------------------------------------------
 */
float similarityScore(char seq1[],char seq2[]);

/** ----------------------------------------------------------
 * readFile() - reads in DNA sequences from a text file 
 * and stores them in an array of structs
 * @param fileName is the file being read
 * @param sequences array of DNA structures
 * @return the number of DNA sequences read from the file
 * ----------------------------------------------------------
 */
int countMatches(char genome[],char seq[],float minScore); 

/** ----------------------------------------------------------
 * readFile() - reads in DNA sequences from a text file 
 * and stores them in an array of structs
 * @param fileName is the file being read
 * @param sequences array of DNA structures
 * @return the number of DNA sequences read from the file
 * ----------------------------------------------------------
 */
float findBestMatch(char genome[],char seq[]); 

/** ----------------------------------------------------------
 * readFile() - reads in DNA sequences from a text file 
 * and stores them in an array of structs
 * @param fileName is the file being read
 * @param sequences array of DNA structures
 * @return the number of DNA sequences read from the file
 * ----------------------------------------------------------
 */
int findBestGenome(DNA sequences[],int numSeq,char unknownSeq[]);

#endif //PEX3FUNCTS_H