#include "Prediction.hpp"

using namespace std;

Prediction::Prediction(User u, Movie m, double pred) {
	this->u = u;
	this->m = m;
	this->prediction = pred;
}

User Prediction::getUser() {
	return u;
}
	
Movie Prediction::getMovie() {
	return m;
}
	
double Prediction::getPrediction() {
	return prediction;
}

void Prediction::setPrediction(double prediction) {
	this->prediction = prediction;
}

void savePrediction(list<Prediction> &predictions) {
	FILE *output;

	output = fopen("submission.csv", "w");
	fprintf(output, "UserId:ItemId,Prediction\n");

	for(list<Prediction>::iterator it_pred = predictions.begin(); it_pred != predictions.end(); it_pred++) {
		fprintf(output, "u%d:i%d,%f\n", it_pred->getUser().getId(), it_pred->getMovie().getId(), it_pred->getPrediction());
	}

	fclose(output);

	// printf("UserId:ItemId,Prediction\n");
	// for(list<Prediction>::iterator it_pred = predictions.begin(); it_pred != predictions.end(); it_pred++) {
	// 	printf("u%d:i%d,%f\n", it_pred->getUser().getId(), it_pred->getMovie().getId(), it_pred->getPrediction());
	// }
}