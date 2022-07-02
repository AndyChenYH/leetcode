import subprocess as sbp

sbp.call("g++ -o one tester.cpp", shell=True);
sbp.call("g++ -o two smallestRange2.cpp", shell=True);
sbp.call("g++ -o three test.cpp", shell=True);
for i in range(100):
    sbp.call("./one", shell=True);
    sbp.call("./two", shell=True);
    sbp.call("./three", shell=True);
    sbp.call("diff out1 out2", shell=True);
