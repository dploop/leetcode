SELECT
    DISTINCT a.*
FROM
    stadium AS a, stadium AS b, stadium AS c
WHERE
    (a.people>99 AND b.people>99 AND c.people>99) AND
    (
        (a.id+1=b.id AND a.id+2=c.id) OR
        (a.id-1=b.id AND a.id+1=c.id) OR
        (a.id-1=b.id AND a.id-2=c.id)
    )
ORDER BY a.id;
