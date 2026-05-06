-- Write your query below


SELECT DISTINCT account_id
FROM (SELECT 
    account_id,
    ip_address, 
    login, 
    logout,
    LEAD(ip_address) OVER(PARTITION BY account_id ORDER BY login, logout) 
        as next_ip_addr,
    LEAD(login) OVER(PARTITION BY account_id ORDER BY login, logout) 
        as next_login,
    LEAD(logout) OVER(PARTITION BY account_id ORDER BY login, logout) 
        as next_logout
FROM log_info)
WHERE next_login IS NOT NULL 
    AND ip_address != next_ip_addr 
    AND next_login <= logout
GROUP BY account_id;
