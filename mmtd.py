# ==============================================================================
# MINI PROYEK: SISTEM PENGECEKAN AKSES UJIAN E-LEARNING
# Mata Kuliah : Logika Matematika / Teknologi Informasi
# Topik       : Logika Proposisi & Tabel Kebenaran (Konjungsi 3 Variabel)
#
# DEFINISI PROPOSISI ATOMIK:
#   p : Mahasiswa sudah login ke sistem.
#   q : UKT mahasiswa sudah dibayar.
#   r : Mahasiswa terdaftar pada mata kuliah ini.
#   s : Mahasiswa diperbolehkan mengikuti ujian (Proposisi Hasil / Output).
#
# EKSPRESI LOGIKA:
#   s ≡ p ∧ q ∧ r
# ==============================================================================

def main():
    print("=" * 68)
    print(" SISTEM PENGECEKAN AKSES UJIAN E-LEARNING")
    print("   Modul Logika Matematika: Ekspresi Logika (s ≡ p ∧ q ∧ r)")
    print("=" * 68)

    print("\n DEKLARASI PROPOSISI ATOMIK:")
    print("   • p : Mahasiswa sudah login")
    print("   • q : UKT sudah dibayar")
    print("   • r : Terdaftar pada mata kuliah")
    print("   • s : Mahasiswa diperbolehkan mengikuti ujian (Hasil)")

    # 1. INPUT DATA MAHASISWA
    print("\n PENGISIAN STATUS MAHASISWA")
    print("   (Ketik 'true' / 'ya' / '1' jika BENAR, atau 'false' / 'tidak' / '0' jika SALAH)")
    print("-" * 68)

    def ask_boolean(prompt_text):
        while True:
            val = input(prompt_text).strip().lower()
            if val in ["true", "ya", "y", "1"]:
                return True
            elif val in ["false", "tidak", "t", "0"]:
                return False
            else:
                print("    Input tidak valid! Harap ketik 'true' atau 'false'.")

    p = ask_boolean(" Proposisi p (Sudah Login?):............ ")
    q = ask_boolean(" Proposisi q (UKT Sudah Dibayar?):....... ")
    r = ask_boolean(" Proposisi r (Terdaftar Mata Kuliah?):... ")

    # 2. EVALUASI EKSPRESI LOGIKA: s ≡ p ∧ q ∧ r
    s = p and q and r

    # 3. MENCETAK TABEL KEBENARAN LENGKAP (8 KOMBINASI)
    print("\n" + "=" * 68)
    print(" TABEL KEBENARAN LENGKAP SISTEM (s ≡ p ∧ q ∧ r)")
    print("=" * 68)
    print(f"| No | Login (p) | Bayar (q) | Daftar (r) | HASIL (s)      | Catatan")
    print("-" * 68)

    row_num = 1
    for p_val in [True, False]:
        for q_val in [True, False]:
            for r_val in [True, False]:
                s_val = p_val and q_val and r_val

                str_p = "BENAR" if p_val else "SALAH"
                str_q = "BENAR" if q_val else "SALAH"
                str_r = "BENAR" if r_val else "SALAH"
                str_s = " DIPERBOLEHKAN" if s_val else "❌ DITOLAK"

                is_user_input = (p_val == p) and (q_val == q) and (r_val == r)
                marker = " [INPUT SAAT INI]" if is_user_input else ""

                print(f"| {row_num:<2} |  {str_p:<7}  |  {str_q:<7}  |  {str_r:<7}   | {str_s:<14} | {marker}")
                row_num += 1

    print("=" * 68)

    # 4. HASIL KESIMPULAN DARI INPUT
    print("\n" + "=" * 68)
    print(" KESIMPULAN & ANALISIS LOGIKA DARI INPUT MAHASISWA")
    print("=" * 68)

    if s:
        print(" KESIMPULAN (s = BENAR): Mahasiswa DIPERBOLEHKAN mengikuti ujian.")
        print("   Alasan: Semua syarat/proposisi (p ∧ q ∧ r) bernilai BENAR (True).")
    else:
        print(" KESIMPULAN (s = SALAH): Mahasiswa TIDAK BISA mengikuti ujian.")
        print("   Alasan: Terdapat syarat yang BELUM TERPENUHI (Bernilai SALAH/False):")
        if not p:
            print("           - [p] Mahasiswa BELUM LOGIN ke sistem e-learning.")
        if not q:
            print("           - [q] Pembayaran UKT BELUM LUNAS.")
        if not r:
            print("           - [r] Mahasiswa BELUM TERDAFTAR pada mata kuliah ini.")

    # 5. PSEUDOCODE
    print("\n" + "=" * 68)
    print(" PSEUDOCODE SISTEM (TERJEMAHAN LOGIKA)")
    print("=" * 68)
    print("ALGORITMA CekAksesUjianElearning")
    print("DEKLARASI:")
    print("    p, q, r, s : BOOLEAN")
    print("ALGORITMA:")
    print("    READ(p, q, r)")
    print("    s <- p AND q AND r")
    print("    IF s = TRUE THEN")
    print("        WRITE('Akses Ujian Diberikan: DIPERBOLEHKAN')")
    print("    ELSE")
    print("        WRITE('Akses Ujian Ditolak: SYARAT BELUM LENGKAP')")
    print("    ENDIF")
    print("=" * 68)

if __name__ == "__main__":
    main()