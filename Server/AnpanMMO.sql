-- MySQL dump 10.16  Distrib 10.1.19-MariaDB, for Win32 (AMD64)
--
-- Host: localhost    Database: localhost
-- ------------------------------------------------------
-- Server version	10.1.19-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `CharacterData`
--

DROP TABLE IF EXISTS `CharacterData`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `CharacterData` (
  `CharacterId` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `CustomerId` int(11) DEFAULT NULL,
  `Name` varchar(128) DEFAULT NULL,
  `Job` int(11) DEFAULT NULL,
  `Level` int(10) unsigned DEFAULT NULL,
  `Exp` int(11) DEFAULT NULL,
  `Gold` int(10) unsigned DEFAULT NULL,
  `LastArea` int(10) unsigned DEFAULT NULL,
  `LastX` float DEFAULT NULL,
  `LastY` float DEFAULT NULL,
  `LastZ` float DEFAULT NULL,
  PRIMARY KEY (`CharacterId`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `ItemData`
--

DROP TABLE IF EXISTS `ItemData`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ItemData` (
  `CharacterId` int(10) unsigned DEFAULT NULL,
  `ItemId` int(10) unsigned DEFAULT NULL,
  `Count` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `ItemShortcut`
--

DROP TABLE IF EXISTS `ItemShortcut`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ItemShortcut` (
  `CharacterId` int(10) unsigned NOT NULL,
  `ItemId1` int(10) unsigned DEFAULT NULL,
  `ItemId2` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`CharacterId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `QuestData`
--

DROP TABLE IF EXISTS `QuestData`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `QuestData` (
  `CharacterId` int(10) unsigned DEFAULT NULL,
  `QuestId` int(10) unsigned DEFAULT NULL,
  `StageNo` int(10) unsigned DEFAULT NULL,
  `KillCount` int(10) unsigned DEFAULT NULL,
  `State` tinyint(3) unsigned DEFAULT NULL,
  `IsActive` tinyint(3) unsigned DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `ScriptFlags`
--

DROP TABLE IF EXISTS `ScriptFlags`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ScriptFlags` (
  `CharacterId` int(10) unsigned NOT NULL,
  `BitField1` int(10) unsigned DEFAULT NULL,
  `BitField2` int(10) unsigned DEFAULT NULL,
  `BitField3` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`CharacterId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `SkillData`
--

DROP TABLE IF EXISTS `SkillData`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `SkillData` (
  `CharacterId` int(10) unsigned NOT NULL,
  `NormalAttackId` int(10) unsigned DEFAULT NULL,
  `Skill1` int(10) unsigned DEFAULT NULL,
  `Skill2` int(10) unsigned DEFAULT NULL,
  `Skill3` int(10) unsigned DEFAULT NULL,
  `Skill4` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`CharacterId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `SkillTree`
--

DROP TABLE IF EXISTS `SkillTree`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `SkillTree` (
  `CharacterId` int(10) unsigned DEFAULT NULL,
  `NodeId` int(10) unsigned DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `UserData`
--

DROP TABLE IF EXISTS `UserData`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `UserData` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `UserCode` varchar(32) DEFAULT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-01-07 18:53:45
