############################# Makefile ##########################
all: tp2
tp2:
	g++ recommender.cpp model/Matrix.cpp model/Movie.cpp model/User.cpp model/Prediction.cpp model/Rating.cpp algorithm/TFIDFInvertedIndex.cpp algorithm/TFIDFInvertedKey.cpp algorithm/TFIDFInvertedValue.cpp algorithm/TFIDFDirectIndex.cpp algorithm/TFIDFDirectKey.cpp algorithm/TFIDFDirectValue.cpp parser/ParameterParser.cpp -o recommender

clean: clean
	rm -rf */*.o

run: run
	./recommender content.csv ratings.csv targets.csv
