-- MySQL dump 10.13  Distrib 8.0.21, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: facturacionempresa
-- ------------------------------------------------------
-- Server version	8.0.21

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `factura`
--

DROP TABLE IF EXISTS `factura`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `factura` (
  `id_factura` int NOT NULL AUTO_INCREMENT,
  `num_talonario` int NOT NULL,
  `num_cliente` int NOT NULL,
  `fecha` date NOT NULL,
  `numero_factura` int NOT NULL,
  `num_items` int NOT NULL,
  `subtotal` decimal(7,2) NOT NULL,
  `iva21` decimal(7,2) NOT NULL,
  `total` decimal(7,2) NOT NULL,
  `sucursal` int NOT NULL,
  PRIMARY KEY (`id_factura`),
  KEY `num_talonario_idx` (`num_talonario`),
  KEY `num_cliente_idx` (`num_cliente`),
  KEY `num_items_idx` (`num_items`),
  CONSTRAINT `num_cliente` FOREIGN KEY (`num_cliente`) REFERENCES `cliente_proveedor` (`id_empresa`),
  CONSTRAINT `num_items` FOREIGN KEY (`num_items`) REFERENCES `items` (`idItem`),
  CONSTRAINT `num_talonario` FOREIGN KEY (`num_talonario`) REFERENCES `talonario` (`numero_talonario`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `factura`
--

LOCK TABLES `factura` WRITE;
/*!40000 ALTER TABLE `factura` DISABLE KEYS */;
INSERT INTO `factura` VALUES (2,1002,2233,'2020-08-19',68,1,11.00,2.31,11.31),(3,1023,5566,'2020-07-02',21,2,27.40,5.75,33.15),(4,1041,3344,'2020-11-19',7,8,27.50,5.78,33.27),(5,1002,5566,'2020-07-08',96,11,11.00,2.31,11.31);
/*!40000 ALTER TABLE `factura` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-07-30 18:10:07
