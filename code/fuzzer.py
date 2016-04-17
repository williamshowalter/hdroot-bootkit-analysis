import subprocess

PATH_TO_HDROOT = "C:\\Users\\admin\\Desktop\\HDRoot\\hdroot.exe"
f = open ("C:\\Users\\admin\\Desktop\\fuzzer_results.txt", "wt")

def recurse_end(theString):
	if len(theString) == 0:
		return ""
	if theString[-1:] != 'z':
		return theString[:-1] + chr(ord(theString[-1:])+1)
	else:
		return recurse_end(theString[:-1]) + 'a'

string_fuzz = "a"
init_output = subprocess.check_output("%s %s" % (PATH_TO_HDROOT,string_fuzz))

while len(string_fuzz) < 6:
	string_fuzz = recurse_end(string_fuzz)
	print string_fuzz
	if string_fuzz == 'a' * len(string_fuzz):
		string_fuzz += 'a'
	if subprocess.check_output("%s %s" % (PATH_TO_HDROOT,string_fuzz)) != init_output:
		print "********* %s **********" % (string_fuzz)
		f.write(string_fuzz + "\n")