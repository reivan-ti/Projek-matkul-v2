// ==============================================================================
// MINI PROYEK: SISTEM PENGECEKAN AKSES UJIAN E-LEARNING
// Mata Kuliah : Logika Matematika / Teknologi Informasi
// Topik       : Logika Proposisi & Tabel Kebenaran (Konjungsi 4 Variabel)
//
// DEFINISI PROPOSISI ATOMIK:
//   p : Mahasiswa sudah login ke sistem.
//   q : UKT mahasiswa sudah dibayar.
//   r : Mahasiswa terdaftar pada mata kuliah ini.
//   t : Mahasiswa tidak sedang dikenai sanksi akademik.
//   s : Mahasiswa diperbolehkan mengikuti ujian (Hasil / Output).
//
// EKSPRESI LOGIKA:  s = p && q && r && t
// ==============================================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

// ─────────────────────────────────────────────────────────────────────
// FUNGSI: Membuat garis pemisah tampilan
// ─────────────────────────────────────────────────────────────────────
string garis(int panjang, char karakter = '=') {
    return string(panjang, karakter);
}

// ─────────────────────────────────────────────────────────────────────
// FUNGSI: Membaca input boolean dari pengguna
// ─────────────────────────────────────────────────────────────────────
bool askBoolean(const string &promptText) {
    string val;
    while (true) {
        cout << promptText;
        getline(cin, val);

        // Ubah ke huruf kecil
        transform(val.begin(), val.end(), val.begin(), ::tolower);

        if (val == "true" || val == "ya" || val == "y" || val == "1") {
            return true;
        } else if (val == "false" || val == "tidak" || val == "t" || val == "0") {
            return false;
        } else {
            cout << "     Input tidak valid! Ketik ya / tidak atau 1 / 0\n";
        }
    }
}

// ─────────────────────────────────────────────────────────────────────
// FUNGSI: Mengubah nilai boolean ke teks status
// ─────────────────────────────────────────────────────────────────────
string boolToStatus(bool val) {
    return val ? "BENAR" : "SALAH";
}

// ─────────────────────────────────────────────────────────────────────
// PROGRAM UTAMA
// ─────────────────────────────────────────────────────────────────────
int main() {
    cout << garis(74) << "\n";
    cout << " SISTEM PENGECEKAN AKSES UJIAN E-LEARNING\n";
    cout << "   Logika Matematika: s = p AND q AND r AND t\n";
    cout << garis(74) << "\n";

    cout << "\n DEKLARASI PROPOSISI:\n";
    cout << "   p : Sudah Login       q : UKT Lunas\n";
    cout << "   r : Terdaftar MK      t : Bebas Sanksi Akademik\n";

    cout << "\n PENGISIAN STATUS MAHASISWA\n";
    cout << "   (Ketik ya / 1 = BENAR,   tidak / 0 = SALAH)\n";
    cout << garis(74, '-') << "\n";

    // Input data dari pengguna
    bool p = askBoolean(" Proposisi p (Sudah Login?):.................... ");
    bool q = askBoolean(" Proposisi q (UKT Sudah Dibayar?):.............. ");
    bool r = askBoolean(" Proposisi r (Terdaftar Mata Kuliah?):.......... ");
    bool t = askBoolean(" Proposisi t (Bebas Sanksi Akademik?):.......... ");

    // Evaluasi ekspresi logika: KONJUNGSI — SEMUA HARUS BENAR
    bool s = p && q && r && t;  //  PAKAI && BUKAN AND!

    // ─────────────────────────────────────────────────────────────────
    // TABEL KEBENARAN LENGKAP (16 KOMBINASI)
    // ─────────────────────────────────────────────────────────────────
    cout << "\n" << garis(90) << "\n";
    cout << "                   TABEL KEBENARAN (4 VARIABEL)\n";
    cout << garis(90) << "\n";
    cout << "| No | Login(p) | Bayar(q) | Daftar(r) | Bebas Sanksi(t) |    HASIL(s)    |\n";
    cout << garis(90, '-') << "\n";

    int nomor = 1;
    for (int pv = 1; pv >= 0; pv--) {
        for (int qv = 1; qv >= 0; qv--) {
            for (int rv = 1; rv >= 0; rv--) {
                for (int tv = 1; tv >= 0; tv--) {
                    bool pVal = pv, qVal = qv, rVal = rv, tVal = tv;
                    bool sVal = pVal && qVal && rVal && tVal;

                    string strP = boolToStatus(pVal);
                    string strQ = boolToStatus(qVal);
                    string strR = boolToStatus(rVal);
                    string strT = boolToStatus(tVal);
                    string strS = sVal ? "DIPERBOLEHKAN" : "DITOLAK";

                    bool cocokInput = (pVal == p) && (qVal == q) && (rVal == r) && (tVal == t);
                    string tanda = cocokInput ? "  ← INPUT ANDA" : "";

                    cout << "| " << setw(2) << nomor << " |  "
                         << setw(7) << left << strP << "  |  "
                         << setw(7) << left << strQ << "  |  "
                         << setw(7) << left << strR << "  |  "
                         << setw(14) << left << strT << " | "
                         << setw(14) << left << strS << " |" << tanda << "\n";
                    nomor++;
                }
            }
        }
    }
    cout << garis(90) << "\n";

    // ─────────────────────────────────────────────────────────────────
    // KESIMPULAN
    // ─────────────────────────────────────────────────────────────────
    cout << "\n" << garis(74) << "\n";
    cout << " KESIMPULAN HASIL PENGECEKAN\n";
    cout << garis(74) << "\n";

    if (s) {
        cout << "  DIPERBOLEHKAN MENGIKUTI UJIAN!\n";
        cout << "   Semua syarat terpenuhi: p ∧ q ∧ r ∧ t = BENAR\n";
    } else {
        cout << "  DITOLAK — TIDAK BISA MENGIKUTI UJIAN!\n";
        cout << "   Syarat yang belum terpenuhi:\n";
        if (!p) cout << "       p = SALAH → Belum Login ke sistem\n";
        if (!q) cout << "       q = SALAH → UKT Belum Lunas\n";
        if (!r) cout << "       r = SALAH → Belum Terdaftar Mata Kuliah\n";
        if (!t) cout << "       t = SALAH → Sedang Dikenai Sanksi Akademik\n";
    }
    cout << garis(74) << "\n";

    // ─────────────────────────────────────────────────────────────────
    // PSEUDOCODE
    // ─────────────────────────────────────────────────────────────────
    cout << "\n" << garis(74) << "\n";
    cout << " PSEUDOCODE SISTEM\n";
    cout << garis(74) << "\n";
    cout << "ALGORITMA CekAksesUjian\n";
    cout << "DEKLARASI:\n";
    cout << "    p, q, r, t, s : BOOLEAN\n";
    cout << "ALGORITMA:\n";
    cout << "    READ(p, q, r, t)\n";
    cout << "    s ← p AND q AND r AND t\n";
    cout << "    IF s = TRUE THEN\n";
    cout << "        WRITE('Akses: DIPERBOLEHKAN')\n";
    cout << "    ELSE\n";
    cout << "        WRITE('Akses: DITOLAK')\n";
    cout << "    ENDIF\n";
    cout << garis(74) << "\n";

    return 0;
}