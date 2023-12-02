#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SimpleLinearRegression {
public:
    void fit(vector<double> X, vector<double> y) {
        int n = X.size();

        double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x_squared = 0.0;
        for (int i = 0; i < n; i++) {
            sum_x += X[i];
            sum_y += y[i];
            sum_xy += X[i] * y[i];
            sum_x_squared += X[i] * X[i];
        }

        double beta_1 = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x * sum_x);
        double beta_0 = (sum_y - beta_1 * sum_x) / n;

        beta_0_ = beta_0;
        beta_1_ = beta_1;
    }

    double predict(double x) {
        return beta_0_ + beta_1_ * x;
    }

    void printEquation() {
        cout << "Ecuación de Regresión: Y = " << beta_0_ << " + " << beta_1_ << " * X" << endl;
    }

private:
    double beta_0_; 
    double beta_1_; 
};

int main() {
    vector<double> Independiente = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> Dependiente = {2, 4, 6, 8, 10, 12, 14, 16, 18};

    SimpleLinearRegression model;
    model.fit(Independiente, Dependiente);
    model.printEquation();

    double x_value = 69;

    double predicted_sales = model.predict(x_value);

    cout << "Para X = " << x_value << ", Y predicho = " << predicted_sales << endl;

    return 0;
}