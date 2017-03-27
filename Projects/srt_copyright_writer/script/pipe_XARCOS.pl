#!/usr/local/bin/perl

sub trim($)
{
        my $string = shift;
        $string =~ s/^\s+//;
        $string =~ s/\s+$//;
        return $string;
}
# Left trim function to remove leading whitespace
sub ltrim($)
{
        my $string = shift;
        $string =~ s/^\s+//;
        return $string;
}
# Right trim function to remove trailing whitespace
sub rtrim($)
{
        my $string = shift;
        $string =~ s/\s+$//;
        return $string;
}

#################################################################################################################





	opendir(DATADIR, "$ARGV[0]");



	@files = readdir(DATADIR);
	$a = scalar(@files);
	$i = 0;
# print "$a $argv[0] \n";
	while ($i < $a) {

		if ($files[$i] ne '.' && $files[$i] ne '..' ) {
			
			opendir(DATADIR2, "$ARGV[0]/$files[$i]");

			@files2 = readdir(DATADIR2);

			$a2 = scalar(@files2);

			$i2 = 0;
			 while ($i2 < $a2) {
				if ($files2[$i2] ne '.' && $files2[$i2] ne '..' ) {
# 					print "$files2[$i2]\n";

# # # # # # # # # # # # # # # # # ///////////////////////////////////////////////////////////////////////////////////////////////////////////
					opendir(DATADIR3, "$ARGV[0]/$files[$i]/$files2[$i2]");
					@files3 = readdir(DATADIR3);
					$a3 = scalar(@files3);
					$i3 = 0;

					print "$ARGV[0]/$files[$i]/$files2[$i2]/conf.txt\n";
					open FILE, "$ARGV[0]/$files[$i]/$files2[$i2]/conf.txt" or die $!;
					$line = readline(FILE);
					$line = readline(FILE);
					$line = readline(FILE);
					$line = readline(FILE);
					$line = readline(FILE);
					@restfreq = split("=",$line);
# 					print "@restfreq[0] = @restfreq[1]\n";
					$rfreq = trim(@restfreq[1]);
					close FILE;
					while ($i3 < $a3) {
						if ($files3[$i3] ne '.' && $files3[$i3] ne '..' ) {
# 							print "$files3[$i3]\n";
# # # # # # # # # # # # # # # # # ///////////////////////////////////////////////////////////////////////////////////////////////////////////
							opendir(DATADIR4, "$ARGV[0]/$files[$i]/$files2[$i2]/$files3[$i3]");
							@files4 = readdir(DATADIR4);
							$a4 = scalar(@files4);
							$i4 = 0;


							$filein = '';
							$fileout = '';

							while ($i4 < $a4) {
								if ($files4[$i4] ne '.' && $files4[$i4] ne '..' ) {
# 									print "$files4[$i4]\n";
# # # # # # # # # # # # # # # # # ///////////////////////////////////////////////////////////////////////////////////////////////////////////
									opendir(DATADIR5, "$ARGV[0]/$files[$i]/$files2[$i2]/$files3[$i3]/$files4[$i4]");
									@files5 = readdir(DATADIR5);
									$a5 = scalar(@files5);
									$i5 = 0;


									while ($i5 < $a5) {
										if ($files5[$i5] ne '.' && $files5[$i5] ne '..' ) {


# 											print "Result: $result\n";
											$fileinput  = "$ARGV[0]/$files[$i]/$files2[$i2]/$files3[$i3]/$files4[$i4]/$files5[$i5]";										
											$fileoutput = "$files[$i]_$files2[$i2]_$files3[$i3]_$files4[$i4]_$rfreq"."_$files5[$i5]";

											system("xarcos_fits_writer $fileinput \!$fileoutput @restfreq[1] 10 125");

											$result = index($files4[$i4], "on");
											if ($result == 0) {$filein = "$fileoutput"};
											$result = index($files4[$i4], "off");
											if ($result == 0) {$fileout = "$fileoutput"};							    
# 											print "$fileinput\n";
# 											print "$fileoutput\n";
											}
										$i5++;
										}					
# # # # # # # # # # # # # # # # ///////////////////////////////////////////////////////////////////////////////////////////////////////////	
									}
								$i4++;
								}	
							if ( $filein!='' && $fileout!='') {
								print $cmd = "onoff_xarcos_writer $filein $fileout \!onoff_$filein\n";
								system($cmd);
# 								print "$fileout\n";	
								}
			
# # # # # # # # # # # # # # # # ///////////////////////////////////////////////////////////////////////////////////////////////////////////	
							}
						$i3++;
						}					
# # # # # # # # # # # # # # # # ///////////////////////////////////////////////////////////////////////////////////////////////////////////		    

					}
				$i2++;
				}
			closedir(DATADIR2);      
			}
		$i++;
		}
