blockchainMain: blockchainMain.o blockchain.o
	g++ -g blockchainMain.o blockchain.o -o blockchainMain

blockchainMain.o: blockchainMain.cpp blockchain.h
		g++ -g blockchainMain.cpp -c

blockchain.o: blockchain.cpp blockchain.h
	g++ -g blockchain.cpp -c

clean:
	rm blockchainMain blockchainMain.o blockchain.o
