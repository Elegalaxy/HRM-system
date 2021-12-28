clean:
	rm main
	clear
	make main
	./main

notclean:
	clear
	make main
	./main

main: 
	g++ -std=c++17 -o main Time.h Time.cpp Account.h Account.cpp Admin.h Admin.cpp Employee.h Employee.cpp HRM_System.cpp