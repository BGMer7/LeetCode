SELECT Score,
    dense_rank() over (
        ORDER BY Score DESC
    ) as `Rank`
FROM Scores;