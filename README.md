This is a quick README for the following packages:

1. srt_class_writer
2. srt_class_onoff
3. srt_class_merge 


### Build Download ###

To retrieve the last build just text on your shell:

git clone https://alessio_trois@bitbucket.org/alessio_trois/build_srtclasswriter.git

### Dependencies

GILDAS Version: jul14c (08dec14 11:41 cet)


### INSTALL ###

cd build_srtclasswriter

make install prefix=/complete_path/

### Configuration ###

Please set the environment variable for PFILES

in your .bashrc:    export  PFILES=/complete_path/pfiles

or in your .cshrc:  setenv  PFILES /complete_path/pfiles
                                               
And then insert in your PATH      
                                           
/complete_path/bin

### Usage ###
---------------------------------------------------------------------------
srt_class_writer inputFile outputFile summaryFile 

Output:
outputFile (fits file) and outputFile.gdf (class file)
---------------------------------------------------------------------------

---------------------------------------------------------------------------
srt_onoff_writer inputFileON(fits file) inputFileOFF(fits file) outputFile 

Output:
outputFile (fits file) and outputFile.gdf (class file)
---------------------------------------------------------------------------

---------------------------------------------------------------------------
srt_merge_writer fileList outputFile

Output:
outputFile (fits file) and outputFile.gdf (class file)
---------------------------------------------------------------------------

### Who do I talk to? ###

The reference people at OAC for this project are:

Alessio Trois
atrois@oa-cagliari.inaf.it
+39 070****

Andrea Tarchi 
atarchi@oa-cagliari.inaf.it
+39 070***

SRT Team - Any information contained in this document
is property of the AGILE Team and is strictly
private and confidential. All rights reserved


* Add others team contact# build_getcopyright
