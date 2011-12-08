echo "Test 1.1"
./TP_STL.exe -k keywords.txt fileTest1.txt -e

echo "Test 1.2"
./TP_STL.exe -k keywords.txt -e fileTest1.txt

echo "Test 1.3"
./TP_STL.exe -k -e keywords.txt fileTest1.txt

echo "Test 1.4"
./TP_STL.exe -e keywords.txt -k fileTest1.txt

echo "Test 1.5"
./TP_STL.exe


echo "Test 1.6"
./TP_STL.exe -e -k keywords.txt

echo "Test 1.7"
./TP_STL.exe -f -k keywords.txt

echo "Test 2"
./TP_STL.exe fileTest2.txt fileTest2.txt

echo "Test 3"
./TP_STL.exe fileTest3.txt

echo "Test 4"
./TP_STL.exe -k keywords2.txt fileTest1.txt

echo "Test 5"
./TP_STL.exe fileTest4.txt

echo "Test 6"
./TP_STL.exe -e -k keywords3.txt fileTest1.txt

echo "Test 7"
./TP_STL.exe -e -k key.txt fileTest1.txt

echo "Test 8"
./TP_STL.exe -e fileTest1.txt fileTest2.txt fileTest3.txt toto.txt

echo "Test 9"
./TP_STL.exe -e -k keywords.txt fileTest1.txt fileTest2.txt

echo "Test 10"
./TP_STL.exe -e fileTest1.txt fileTest2.txt

echo "Test 11"
./TP_STL.exe -k keywords.txt fileTest1.txt fileTest2.txt

echo "Test 12"
./TP_STL.exe fileTest1.txt fileTest2.txt
