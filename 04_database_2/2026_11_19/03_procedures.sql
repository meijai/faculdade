USE biblioteca_copia;

-- 7. procedure com parametro OUT
DROP PROCEDURE IF EXISTS sp_total_titulos;
DELIMITER $$
CREATE PROCEDURE sp_total_titulos(OUT p_total INT)
BEGIN
    SELECT COUNT(*) INTO p_total FROM livro;
END$$
DELIMITER ;

CALL sp_total_titulos(@total);
SELECT @total AS total_titulos;

-- 8. procedure para retirar estoque
DROP PROCEDURE IF EXISTS sp_retirar_estoque;
DELIMITER $$
CREATE PROCEDURE sp_retirar_estoque(
    IN p_id_livro INT, IN p_quantidade INT)
BEGIN
    IF p_quantidade IS NULL OR p_quantidade <= 0 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Quantidade deve ser positiva';
    END IF;
    UPDATE livro SET quantidade = quantidade - p_quantidade
    WHERE id = p_id_livro AND quantidade >= p_quantidade;
    IF ROW_COUNT() <> 1 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Livro inexistente ou estoque insuficiente';
    END IF;
END$$
DELIMITER ;

-- teste 1: retirada valida (livro 1 tem 5 unidades)
CALL sp_retirar_estoque(1, 2);
SELECT id, titulo, quantidade FROM livro WHERE id = 1;

-- teste 2: estoque insuficiente (tem que dar erro)
CALL sp_retirar_estoque(1, 100);

-- teste 3: id que nao existe (tem que dar erro)
CALL sp_retirar_estoque(999, 1);
