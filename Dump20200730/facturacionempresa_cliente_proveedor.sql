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
-- Table structure for table `cliente_proveedor`
--

DROP TABLE IF EXISTS `cliente_proveedor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `cliente_proveedor` (
  `id_empresa` int NOT NULL,
  `nombre_comercial` varchar(45) NOT NULL,
  `nombre_fantacia` varchar(45) NOT NULL,
  `telefono` varchar(45) NOT NULL,
  `direccion` varchar(45) NOT NULL,
  `localidad` varchar(45) NOT NULL,
  `piso` int NOT NULL,
  `dpto` varchar(45) NOT NULL,
  `codigo_postal` int NOT NULL,
  `documento` int NOT NULL,
  `condicion_iva` varchar(45) NOT NULL,
  `num_cliente` int NOT NULL,
  `tipo_cliente` int NOT NULL,
  `contacto_nombre` varchar(45) NOT NULL,
  `contacto_dni` int NOT NULL,
  `contacto_cargo` varchar(45) NOT NULL,
  PRIMARY KEY (`id_empresa`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cliente_proveedor`
--

LOCK TABLES `cliente_proveedor` WRITE;
/*!40000 ALTER TABLE `cliente_proveedor` DISABLE KEYS */;
INSERT INTO `cliente_proveedor` VALUES (1122,'Chapa y pintura S.A','Chapitas','011-4683-9452','Pedro lozano 4526','CABA',0,'0',1403,28649812,'RI',137946,0,'Pedro Garcia',14598325,'Director de compras'),(2233,'Alimentos caninos S.R.L','Dogis','011-2468-7895','Concordia 462','CABA',0,'2',1409,23468529,'EX',346852,0,'Juan Marcone',12796432,'Gerente'),(3344,'Aceros Ramos S.R.L','Herramietas Mayoristas','011-1249-7874','Av. Beriro 412','CABA',0,'3',1413,24135764,'RM',234787,1,'Nicolas agustin sanchez',24697235,'Encargado de Ventas'),(4455,'Helos artesanales Fredo E.U','Heladeria Fredo','011-2369-8642','Av. Rivadavia 4795','CABA',1,'0',1412,259763145,'RI',246854,0,'Florencia Martinez',24356741,'Dueño'),(5566,'Mayorista de heramientas S.A','Fischer','011-1469-8534','Nazarre 1468','CABA',2,'1',1404,23795684,'CF',294568,1,'Agostina Rodriguez',29356125,'Director de compras');
/*!40000 ALTER TABLE `cliente_proveedor` ENABLE KEYS */;
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
