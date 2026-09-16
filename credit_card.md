 Credit Card Validation Program — Explained

This program checks whether a credit card number is valid using the Luhn algorithm.

 OOP Concepts Used

None The program is purely procedural: a single 'main()' plus free-standing helper functions, no 'class', no objects, no encapsulation, inheritance, or polymorphism. It's organized using functional decomposition instead — the problem is broken into small, single-purpose functions ('isValid', 'getDigit', 'sumOfOddPlace', etc.) that call each other, rather than into objects with data and behavior bundled together.

Algorithm

The program implements the Luhn algorithm (mod-10 check) for card validation:

1. Read input: get the card number as a 'long long'.
2. Check length: 'getSize' counts the digits; valid cards must have 13–16 digits.
3. Check prefix: 'prefixMatched' (via 'getPrefix') confirms the number starts with a valid issuer prefix — '4' (Visa), '5' (MasterCard), '37' (Amex), or '6' (Discover).
4. Double every second digit from the right ('sumOfDoubleEvenPlace'): walk the digits from the right, double each "even place" digit, and if doubling produces a two-digit result, sum its digits ('getDigit') before adding to the total.
5. Sum the untouched digits ('sumOfOddPlace'): sum the digits in the "odd" positions (not doubled).
6. Combine and check: add both sums together; the card is valid only if the total is divisible by 10.

 Possible Error Points

- Negative or zero input: 'cin >> cardNumber' doesn't reject negative numbers or '0'; 'getSize' assumes a positive number and would misbehave (e.g., return 0 for '0', or loop incorrectly on negatives since '%'/'/' behave differently for negative operands).
- Non-numeric input: If the user types letters or symbols, 'cin' fails silently, leaving 'cardNumber' unset/garbage — there's no input validation or error check on the stream state.
- Overflow: 16-digit numbers are near the upper limit of 'long long'; a 17+ digit entry could overflow and produce wrong results without any warning.
- Even/odd digit-position mix-up: 'sumOfDoubleEvenPlace' and 'sumOfOddPlace' rely on precise digit-stripping ('/10', '/100') to stay in sync; an off-by-one edit to either loop would silently miscount which digits get doubled.
- Leading zeros: Since the number is stored as 'long long', any leading zero in a real card number would be dropped, changing the digit count and potentially failing the length/prefix checks incorrectly.
- Prefix edge case: 'prefixMatched(number, 6)' matches any number starting with '6', but real Discover cards use more specific prefixes ('6011', '65', etc.) — this is a simplification, not a bug, but a source of false positives.
- No feedback on why it's invalid: The program only prints valid/invalid, not which check failed (length, prefix, or checksum) — fine for this exercise, but a common gap if extended.
