-- MySQL Script generated by MySQL Workbench
-- Thu Jul 30 18:08:51 2020
-- Model: New Model    Version: 1.0
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema FacturacionEmpresa
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema FacturacionEmpresa
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `FacturacionEmpresa` DEFAULT CHARACTER SET utf8 ;
USE `FacturacionEmpresa` ;

-- -----------------------------------------------------
-- Table `FacturacionEmpresa`.`Talonario`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `FacturacionEmpresa`.`Talonario` (
  `numero_talonario` INT NOT NULL,
  `codigo` INT NOT NULL,
  `sucursal` INT NOT NULL,
  `cant_hojas` INT NOT NULL,
  `hoja_actual` INT NOT NULL,
  `vencimiento` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`numero_talonario`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `FacturacionEmpresa`.`Cliente_proveedor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `FacturacionEmpresa`.`Cliente_proveedor` (
  `id_empresa` INT NOT NULL,
  `nombre_comercial` VARCHAR(45) NOT NULL,
  `nombre_fantacia` VARCHAR(45) NOT NULL,
  `telefono` VARCHAR(45) NOT NULL,
  `direccion` VARCHAR(45) NOT NULL,
  `piso` INT NOT NULL,
  `dpto` VARCHAR(45) NOT NULL,
  `codigo_postal` INT NOT NULL,
  `documento` INT NOT NULL,
  `condicion_iva` VARCHAR(45) NOT NULL,
  `num_cliente` INT NOT NULL,
  `tipo_cliente` VARCHAR(45) NOT NULL,
  `contacto_nombre` VARCHAR(45) NOT NULL,
  `contacto_dni` INT NOT NULL,
  `contacto_cargo` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id_empresa`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `FacturacionEmpresa`.`Stock`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `FacturacionEmpresa`.`Stock` (
  `idStock` INT NOT NULL AUTO_INCREMENT,
  `nombre` VARCHAR(45) NOT NULL,
  `descripcion` VARCHAR(45) NOT NULL,
  `cantidad` INT NOT NULL,
  `precio_venta` DECIMAL(4) NOT NULL,
  `precio_compra` DECIMAL(4) NOT NULL,
  PRIMARY KEY (`idStock`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `FacturacionEmpresa`.`Items`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `FacturacionEmpresa`.`Items` (
  `idItem` INT NOT NULL AUTO_INCREMENT,
  `id_factura` INT NOT NULL,
  `cantidad` INT NOT NULL,
  `id_codigo` INT NOT NULL,
  `descripcion` VARCHAR(45) NOT NULL,
  `precio_unitario` DECIMAL(4) NOT NULL,
  `Itemscol` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idItem`),
  INDEX `id_codigo_idx` (`id_codigo` ASC) VISIBLE,
  CONSTRAINT `id_codigo`
    FOREIGN KEY (`id_codigo`)
    REFERENCES `FacturacionEmpresa`.`Stock` (`idStock`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `FacturacionEmpresa`.`Factura`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `FacturacionEmpresa`.`Factura` (
  `id_factura` INT NOT NULL,
  `num_talonario` INT NOT NULL,
  `num_cliente` INT NOT NULL,
  `fecha` VARCHAR(45) NOT NULL,
  `numero_factura` INT NOT NULL,
  `num_items` INT NOT NULL,
  `subtotal` DECIMAL(4) NOT NULL,
  `iva21` DECIMAL(4) NOT NULL,
  `total` DECIMAL(4) NOT NULL,
  `sucursal` INT NOT NULL,
  PRIMARY KEY (`id_factura`),
  INDEX `num_talonario_idx` (`num_talonario` ASC) VISIBLE,
  INDEX `num_cliente_idx` (`num_cliente` ASC) VISIBLE,
  INDEX `num_items_idx` (`num_items` ASC) VISIBLE,
  CONSTRAINT `num_talonario`
    FOREIGN KEY (`num_talonario`)
    REFERENCES `FacturacionEmpresa`.`Talonario` (`numero_talonario`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `num_cliente`
    FOREIGN KEY (`num_cliente`)
    REFERENCES `FacturacionEmpresa`.`Cliente_proveedor` (`id_empresa`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `num_items`
    FOREIGN KEY (`num_items`)
    REFERENCES `FacturacionEmpresa`.`Items` (`idItem`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;