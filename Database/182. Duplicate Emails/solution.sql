SELECT email
FROM Person
WHERE email IS NOT NULL
GROUP BY email
HAVING COUNT(email) > 1;