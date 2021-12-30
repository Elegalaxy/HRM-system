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
	g++ -std=c++17 -o main Time.h Time.cpp Account.h Account.cpp Employee.h Employee.cpp Admin.h Admin.cpp HRM_System.cpp