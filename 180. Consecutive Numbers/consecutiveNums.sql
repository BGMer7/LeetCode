SELECT DISTINCT L1.Num as ConsecutiveNums
FROM Logs L1,
    Logs l2,
    Logs l3
WHERE l1.Num = l2.Num
    and l2.Num = l3.Num
    and l1.Id = l2.Id -1
    and l2.Id = l3.Id -1;