////////////////////////////////////////////////////////////////////////////////
// DESCRIPTION
//       Get SRT Copyright 
//       Contributors: SRT Team
//       Author: Alessio Trois (OA Cagliari)
//		
//
// INPUT
//       srt fits 
//
// OUTPUT
//       output filename
//
//
// FILE HISTORY
//                      Authors:        Alessio Trois (OA Cagliari)
//                             		
// NOTICE
//       Any information contained in this software
//       is property of the SRT TEAM and is strictly
//       private and confidential.
//       All rights reserved.
////////////////////////////////////////////////////////////////////////////////////


#include "srt_copyright_writer.h"

using namespace std;

int OpenFits(int argc, char ** argv, fitsfile ** input, fitsfile ** output) {

	int status=0, pkttype=0, pktstype=0;
	char * infile = new char[FLEN_FILENAME];
	char * outfile = new char[FLEN_FILENAME];
	int numpar=0;
	
	
	const time_t tp = time(NULL);
	char *data=ctime(&tp);

	
	printf("\n\nSTART EXECUTION:  %s",data);	
	printf("####################################################\n");
	printf("#########  Task srt_copyright_writer......... starting  #########\n");
	printf("#########         %s         #########\n", version);
	printf("####################################################\n\n\n");
	printf("srt_copyright_writer..................... starting Open3201\n");

	
	
	
	
/////////////////////////////////////////////////////	
	status = PILInit(argc,argv);
	PILGetNumParameters(&numpar);
	
	if ( status != 0 || numpar!=2)
		return 1002;
		
	PILGetString("infile",infile);
	PILGetString("outfile",outfile);
	PILClose(status);
/////////////////////////////////////////////////////	
	
	if (strcmp(infile,outfile)==0) {
		status = 101;
		return status;		
		}

	printf("..........opening input file: %s\n",infile);
	fits_open_file(input, infile, READONLY, &status);
	if (status) {
		return status;
		}



	printf("..........opening output file: %s\n",outfile);
	fits_create_file(output, outfile, &status);
	if (status) {
		return status;
		}		
		
	
	
	fits_copy_file(input[0], output[0], 1, 1, 1, &status);
	
	delete []infile;
	delete []outfile;		
		
	if ( status) {
		printf("srt_copyright_writer..................... exiting Open3201 ERROR: %d", status);		
		fits_report_error(stdout, status);	
		printf("\n");
		return status;			
		}			
	else {
		printf("srt_copyright_writer..................... exiting Open3201 STATUS = 0\n\n");		
		}
	return status;	
	}



int WriteHeader(fitsfile * output){
	int status=0;
	char filename[512];
// 	int hdnum = 0;
// 	char corvers[100];
// 	fits_get_num_hdus(output, &hdnum, &status);
	
	fits_movabs_hdu(output, 1, NULL, &status);
	fits_write_date(output,  &status);
	
	
// 	int fits_write_history(output, char *history,  int *status);
	strcpy(filename, "Sardinia Radio Telescope");	
	fits_update_key(output, TSTRING, "ORIGIN",  filename, NULL, &status);	 	
	
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);	
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);	
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);	
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);	
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);	
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);	
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);	
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);	
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);	
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);	
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);	
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);	
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);
	fits_write_comment(output, "TESTO DA INSERIRE",  &status);	

	
	return status;

	}

	
	
	
int CloseFits(int argc, char ** argv, fitsfile * input, fitsfile * output) {

	printf("srt_copyright_writer..................... starting Close3201\n");
	int status = 0;
	int hdnum = 0;
	
	
	
		
	fits_close_file(input, &status);
	
	fits_get_num_hdus(output, &hdnum, &status);
	for (int i=1; i<=hdnum; ++i) {
		fits_movabs_hdu(output, i, NULL, &status);
		fits_write_chksum(output,&status);
		}
	fits_close_file(output, &status);
	
	
	if ( status) {
		printf("srt_copyright_writer..................... exiting Close3201 ERROR:");		
		fits_report_error(stdout, status);	
		printf("\n");
		return status;			
		}			

	printf("srt_copyright_writer..................... exiting Close3201 STATUS = 0\n\n");		

		
			
	printf("\n\n####################################################\n");
	printf("#########  Task srt_copyright_writer........... exiting #########\n");
	printf("####################################################\n\n\n");				
		
	return status;
	}

	
	
	
int main(int argc,char **argv)
{
int status=0;
fitsfile ** input = new fitsfile*[1];
fitsfile ** output = new fitsfile*[1];




status = OpenFits(argc, argv, input, output);


if (status ==0)	
	status = WriteHeader(output[0]);
	
if (status ==0)	
	status = CloseFits( argc, argv, input[0], output[0]);

	
if (status) {
	fits_report_error(stderr, status);
	}
else {	
	printf("STATUS %d\n",status);
	}	
	
	
delete []input;
delete []output;
exit(status);
}




