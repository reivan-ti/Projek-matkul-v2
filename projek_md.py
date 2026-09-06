# ==================================================
# MINI PROJECT: E-LEARNING EXAM ACCESS SYSTEM
# Course: Mathematical Logic / Information Technology
# ==================================================

print("=" * 55)
print(" E-LEARNING EXAM ACCESS CHECK SYSTEM")
print("=" * 55)

# --------------------------
# 1. DEFINITION OF PROPOSITION (Student Data Input)
# --------------------------
print("\n Enter Student Status (Ketik True / False):")
p = input(" Already logged in?.............: ").lower() == "true"
q = input(" UKT Has Been Paid?.......: ").lower() == "true"
r = input(" Registered Courses?...: ").lower() == "true"

# --------------------------
# 2. LOGIC EXPRESSION (Formula: p AND q AND r)
# --------------------------
can_take_exam = p and q and r

# --------------------------
# 3. SHOW THE TRUTH TABLE (For Report)
# --------------------------
print("\n" + "=" * 55)
print(" TRUTH TABLE")
print("=" * 55)
print(f"Login (p) | Pay (q) | Register (r) | EXAM ACCESS")
print("-" * 55)
status_p = "TRUE" if p else "FALSE"
status_q = "TRUE" if q else "FALSE"
status_r = "TRUE" if r else "FALSE"
status_akses = " ALLOWED" if can_take_exam else " DENIED"
print(f"   {status_p}   |   {status_q}   |   {status_r}   |   {status_akses}")

# --------------------------
# 4. EXPLANATION OF DECISION
# --------------------------
print("\n" + "=" * 55)
print(" CONCLUSION & LOGICAL ANALYSIS")
print("=" * 55)

if can_take_exam:
    print(" CONCLUSION: Students ARE ALLOWED to take the exam.")
    print("   Reason: All logic conditions (p ∧ q ∧ r) are TRUE.")
else:
    print(" CONCLUSION: Students are not allowed to take the exam.")
    print("   Reason: There are conditions that are NOT MET:")
    if not p: print("      - Still NOT LOGGED IN")
    if not q: print("      - UKT NOT PAID")
    if not r: print("      - NOT registered in this course")

# --------------------------
# 5. PSEUDOCODE (Sesuai Tugas)
# --------------------------
print("\n" + "=" * 55)
print(" PSEUDOCODE (TERJEMAHAN LOGIKA)")
print("=" * 55)
print("IF (Login = TRUE) AND (Pay = TRUE) AND (Register = TRUE)")
print("   THEN ALLOW EXAM ACCESS")
print("ELSE")
print("   DENY ACCESS AND DISPLAY ERROR MESSAGE")
print("=" * 55)
