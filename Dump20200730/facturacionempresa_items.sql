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
-- Table structure for table `items`
--

DROP TABLE IF EXISTS `items`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `items` (
  `idItem` int NOT NULL AUTO_INCREMENT,
  `id_factura` int NOT NULL,
  `cantidad` int NOT NULL,
  `id_codigo` int NOT NULL,
  `descripcion` varchar(45) NOT NULL,
  `precio_unitario` decimal(7,2) NOT NULL,
  `sub_total` decimal(7,2) NOT NULL,
  `Itemscol` varchar(45) NOT NULL,
  PRIMARY KEY (`idItem`),
  KEY `id_codigo_idx` (`id_codigo`),
  CONSTRAINT `id_codigo` FOREIGN KEY (`id_codigo`) REFERENCES `stock` (`idStock`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `items`
--

LOCK TABLES `items` WRITE;
/*!40000 ALTER TABLE `items` DISABLE KEYS */;
INSERT INTO `items` VALUES (1,102,20,1,'Tornillo Madera cabeza plana M3 N6',0.55,11.00,'1'),(2,103,13,4,'Tornillo pared M3 philips N3',0.30,3.90,'1'),(5,103,20,7,'Tarugo pared con cabeza N4',0.80,16.00,'2'),(6,103,5,6,'Tornillo pared M3 philips N10',0.80,4.00,'3'),(7,103,5,10,'Tarugo pared con cabeza N10',1.50,7.50,'4'),(8,129,15,3,'Tornillo pared M3 philips N3',0.30,4.50,'1'),(9,129,15,7,'Tornillo pared M3 philips N3',0.80,12.00,'2'),(10,129,20,1,'Tornillo Madera cabeza plana M3 N6',0.30,11.00,'3'),(11,164,30,1,'Tornillo Madera cabeza plana M3 N6',0.55,16.50,'1');
/*!40000 ALTER TABLE `items` ENABLE KEYS */;
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
