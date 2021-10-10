import sys
import getopt
import subprocess
import os

BUILD_TYPE = None

try:
    opts, args = getopt.getopt(sys.argv[1:], "b:", ["build"])
except getopt.GetoptError:
    print('configure.py -b <BUILD_TYPE>')
    sys.exit(2)
for opt, arg in opts:
    if opt == '-h':
        print('configure.py -b <BUILD_TYPE>')
        sys.exit(2)
    elif opt in ("-b"):
        BUILD_TYPE = arg

WORK_DIR = os.path.dirname(os.path.abspath(__file__))

if BUILD_TYPE == None or str(BUILD_TYPE).upper() == "DEBUG":
    subprocess.run(["cmake", "-B", WORK_DIR+"/build",
                   "-DCMAKE_BUILD_TYPE=DEBUG"])
elif str(BUILD_TYPE).upper() == "RELEASE":
    subprocess.run(["cmake", "-B", WORK_DIR+"/build",
                   "-DCMAKE_BUILD_TYPE=RELEASE"])
else:
    print("BUILD_TYPE: " + BUILD_TYPE + " undefined")
