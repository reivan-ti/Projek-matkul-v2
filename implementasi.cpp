#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

// Fungsi menampilkan isi himpunan
void tampilkan_himpunan(const string& nama, const set<string>& himpunan) {
    cout << nama << " = { ";
    if (himpunan.empty()) {
        cout << "(kosong / empty set)";
    } else {
        bool pertama = true;
        for (const auto& anggota : himpunan) {
            if (!pertama) cout << ", ";
            cout << anggota;
            pertama = false;
        }
    }
    cout << " }\n";
    cout << "Jumlah anggota " << nama << " = " << himpunan.size() << "\n";
}

// Gabungan A ∪ B
set<string> gabungan(const set<string>& a, const set<string>& b) {
    set<string> hasil;
    merge(a.begin(), a.end(), b.begin(), b.end(),
          inserter(hasil, hasil.begin()));
    return hasil;
}

// Irisan A ∩ B
set<string> irisan(const set<string>& a, const set<string>& b) {
    set<string> hasil;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(),
                     inserter(hasil, hasil.begin()));
    return hasil;
}

// Selisih A - B
set<string> selisih(const set<string>& a, const set<string>& b) {
    set<string> hasil;
    set_difference(a.begin(), a.end(), b.begin(), b.end(),
                   inserter(hasil, hasil.begin()));
    return hasil;
}

// Selisih Simetris A ⊕ B
set<string> selisih_simetris(const set<string>& a, const set<string>& b) {
    set<string> hasil;
    set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(),
                             inserter(hasil, hasil.begin()));
    return hasil;
}

int main() {
    cout << "============================================================\n";
    cout << " PROGRAM OPERASI HIMPUNAN DATA PENGGUNA SISTEM INFORMASI\n";
    cout << "============================================================\n\n";

    // Himpunan A: pengguna E-Learning
    set<string> pengguna_elearning = {
        "andi", "budi", "citra",
        "dina", "eko", "sry"
    };

    // Himpunan B: pengguna E-Library
    set<string> pengguna_elibrary = {
        "dina", "eko", "sry",
        "reivan", ""
    };

    cout << "-- DATA HIMPUNAN AWAL --\n";
    tampilkan_himpunan("A (Pengguna E-Learning)", pengguna_elearning);
    cout << "\n";
    tampilkan_himpunan("B (Pengguna E-Library)", pengguna_elibrary);

    // Hitung semua operasi
    auto hasil_gabungan     = gabungan(pengguna_elearning, pengguna_elibrary);
    auto hasil_irisan       = irisan(pengguna_elearning, pengguna_elibrary);
    auto hasil_selisih_ab   = selisih(pengguna_elearning, pengguna_elibrary);
    auto hasil_selisih_ba   = selisih(pengguna_elibrary, pengguna_elearning);
    auto hasil_simetris     = selisih_simetris(pengguna_elearning, pengguna_elibrary);

    // Tampilkan hasil
    cout << "\n-- HASIL OPERASI HIMPUNAN --\n";

    cout << "\n[1] Gabungan (Union) A U B\n";
    cout << "    -> Seluruh pengguna yang memakai E-Learning ATAU E-Library\n";
    tampilkan_himpunan("A U B", hasil_gabungan);

    cout << "\n[2] Irisan (Intersection) A ∩ B\n";
    cout << "    -> Pengguna yang memakai KEDUA aplikasi sekaligus\n";
    tampilkan_himpunan("A ∩ B", hasil_irisan);

    cout << "\n[3] Selisih (Difference) A - B\n";
    cout << "    -> Pengguna yang HANYA memakai E-Learning saja\n";
    tampilkan_himpunan("A - B", hasil_selisih_ab);

    cout << "\n[4] Selisih (Difference) B - A\n";
    cout << "    -> Pengguna yang HANYA memakai E-Library saja\n";
    tampilkan_himpunan("B - A", hasil_selisih_ba);

    cout << "\n[5] Selisih Simetris (Symmetric Difference) A ⊕ B\n";
    cout << "    -> Pengguna yang memakai TEPAT SATU aplikasi (tidak keduanya)\n";
    tampilkan_himpunan("A ⊕ B", hasil_simetris);

    cout << "\n============================================================\n";
    cout << " PROGRAM SELESAI DIJALANKAN\n";
    cout << "============================================================\n";

    return 0;
}