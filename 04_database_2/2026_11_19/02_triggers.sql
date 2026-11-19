USE biblioteca_copia;

-- 4. tabela de auditoria de preco
CREATE TABLE IF NOT EXISTS auditoria_preco (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    id_livro INT NOT NULL,
    preco_anterior DECIMAL(10,2) NOT NULL,
    preco_novo DECIMAL(10,2) NOT NULL,
    alterado_em DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB;

-- 5. trigger que registra quando o preco muda
DROP TRIGGER IF EXISTS trg_audita_preco;
DELIMITER $$
CREATE TRIGGER trg_audita_preco
AFTER UPDATE ON livro
FOR EACH ROW
BEGIN
    IF NOT (OLD.preco <=> NEW.preco) THEN
        INSERT INTO auditoria_preco (id_livro, preco_anterior, preco_novo)
        VALUES (NEW.id, OLD.preco, NEW.preco);
    END IF;
END$$
DELIMITER ;

-- teste do 5
UPDATE livro SET preco = preco + 5 WHERE id = 1;
SELECT * FROM auditoria_preco ORDER BY id DESC LIMIT 5;

-- 6. trigger que nao deixa inserir preco ou quantidade negativos
DROP TRIGGER IF EXISTS trg_valida_livro;
DELIMITER $$
CREATE TRIGGER trg_valida_livro
BEFORE INSERT ON livro
FOR EACH ROW
BEGIN
    IF NEW.preco < 0 OR NEW.quantidade < 0 THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'Preco/quantidade invalidos';
    END IF;
END$$
DELIMITER ;
