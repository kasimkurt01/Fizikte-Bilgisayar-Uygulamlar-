#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// 1. mertebeden diferansiyel denklem sistemi
// y[0] = y
// y[1] = y'
vector<double> dy1(double x, const vector<double>& y) {
	
    return { y[1], (4.0 * pow(x,2) - 2.0) * y[0] };
}

// 4. Mertebe Runge-Kutta (RK4) Çözücü
// Verilen y'(0) = u baþlangýç eðimi için y(1) deðerini hesaplar
double RK4(double u, double dx, int steps, vector<double>& x_vals, vector<vector<double>>& y_vals) {
   
    vector<double> k1,k2,k3,k4,y_temp1,y_temp2,y_temp3,y_temp4;
    vector<double> y = { 1.0, u }; // Baþlangýç koþullarý: y(0)=1, y'(0)=u
	double x = 0.0;
    

    x_vals.clear();
    y_vals.clear();

    x_vals.push_back(x);
    y_vals.push_back(y);

    for (int i = 0; i < steps; ++i) {
        k1 = dy1(x, y);

        y_temp1 = { y[0] + 0.5 * dx * k1[0], y[1] + 0.5 * dx * k1[1] };
        k2 = dy1(x + 0.5 * dx, y_temp1);

        y_temp2 = { y[0] + 0.5 * dx * k2[0], y[1] + 0.5 * dx * k2[1] };
        k3 = dy1(x + 0.5 * dx, y_temp2);

        y_temp3 = { y[0] + dx * k3[0], y[1] + dx * k3[1] };
        k4 = dy1(x + dx, y_temp3);

        y[0] += (dx / 6.0) * (k1[0] + 2.0 * k2[0] + 2.0 * k3[0] + k4[0]);
        y[1] += (dx / 6.0) * (k1[1] + 2.0 * k2[1] + 2.0 * k3[1] + k4[1]);
        x += dx;

        x_vals.push_back(x);
        y_vals.push_back(y);
    }
    return y[0]; // x=1 noktasýndaki y deðerini döndürür
}

int main() {
    double target_y1 = 1.0 / exp(1.0); // Hedef sýnýr koþulu: y(1) = 1/e
    double tol = 1e-6;                 // Hata toleransý
    double dx = 0.01;                  // Adým büyüklüðü
    int steps = static_cast<int>(1.0 / dx);

    // Atýþ (Shooting) Yöntemi için Sekant algoritmasý baþlangýç tahminleri
    double u0 = 1.0;  // y'(0) için 1. tahmin
    double u1 = -1.0; // y'(0) için 2. tahmin

    vector<double> x_vals;
    vector<vector<double>> y_vals;

    // Hata fonksiyonu F(u) = y_hesaplanan(1, u) - y_hedef(1)
    double F0 = RK4(u0, dx, steps, x_vals, y_vals) - target_y1;
    double F1 = RK4(u1, dx, steps, x_vals, y_vals) - target_y1;
    cout << " F0 :" << F0 <<"\n F1 :" << F1 << endl;
    double u_next;
    int max_iter = 100;
    int iter = 0;

    // Hedef deðere ulaþana kadar Sekant iterasyonu
    
    while (abs(F1) > tol && iter < max_iter) {
        // Sekant formülü ile yeni tahmini hesapla
        u_next = u1 - F1 * (u1 - u0) / (F1 - F0);

        u0 = u1;
        F0 = F1;
        u1 = u_next;
        F1 = RK4(u1, dx, steps, x_vals, y_vals) - target_y1;
 cout << " F0 :" << F0 <<"\n F1 :" << F1 << endl;
        iter++;
    }

    cout << "--- Atis Yontemi ve RK4 Cozumu ---\n";
    cout << "Iterasyon Sayisi: " << iter << "\n";
    cout << "Bulunan baslangic egimi y'(0): " << fixed << setprecision(10) << u1 << "\n";
    cout << "Hedef y(1) degeri : " << target_y1 << "\n";
    cout << "Ulasilan y(1) degeri: " << RK4(u1, dx, steps, x_vals, y_vals) << "\n\n";

    cout << "--- x ve y(x) Degerleri (Her 10 adimda bir) ---\n";
    for (size_t i = 0; i <= steps; i += 10) {
        cout << "x = " << fixed << setprecision(2) << x_vals[i]
             << " \t y(x) = " << fixed << setprecision(6) << y_vals[i][0] << "\n";
    }

    return 0;
}