-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Anamakine: localhost
-- Üretim Zamanı: 18 Haz 2022, 02:39:24
-- Sunucu sürümü: 10.1.38-MariaDB
-- PHP Sürümü: 5.6.40

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Veritabanı: `netflixdb`
--

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Acted_In`
--

CREATE TABLE `Acted_In` (
  `MovieID` int(11) NOT NULL,
  `ActorID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `Acted_In`
--

INSERT INTO `Acted_In` (`MovieID`, `ActorID`) VALUES
(1, 55001),
(2, 55002),
(3, 55003),
(5, 55004),
(5, 55045),
(7, 55041),
(8, 55005),
(9, 55038),
(11, 55043),
(12, 55034);

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Actor`
--

CREATE TABLE `Actor` (
  `ActorName` varchar(25) DEFAULT NULL,
  `Gender` varchar(10) DEFAULT NULL,
  `ActorID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `Actor`
--

INSERT INTO `Actor` (`ActorName`, `Gender`, `ActorID`) VALUES
('Matthew McConaughey', 'Male', 55001),
('Lindsay Lohan', 'Female', 55002),
('Ryan Gosling', 'Male', 55003),
('Christian Bale', 'Male', 55004),
('Justin Timberlake', 'Male', 55005),
('Tom Hanks', 'Male', 55034),
('Miles Teller', 'Male', 55038),
('Zendaya', 'Female', 55041),
('Jennifer Lawrance', 'Female', 55043),
('Hugh Jackman', 'Male', 55045);

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Directed`
--

CREATE TABLE `Directed` (
  `MovieID` int(11) NOT NULL,
  `DirID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `Directed`
--

INSERT INTO `Directed` (`MovieID`, `DirID`) VALUES
(1, 82001),
(2, 82003),
(3, 82329),
(5, 82001),
(7, 83565),
(8, 85001),
(9, 82329),
(11, 83456),
(12, 84007),
(13, 85002);

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Director`
--

CREATE TABLE `Director` (
  `DirectorName` varchar(25) DEFAULT NULL,
  `DirID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `Director`
--

INSERT INTO `Director` (`DirectorName`, `DirID`) VALUES
('Christopher Nolan', 82001),
('Mark Waters', 82003),
('Damien Chazelle', 82329),
('Gary Ross', 83456),
('Denis Villeneuve', 83565),
('Frank Darabont', 84007),
('Andrew Niccol', 85001),
('Cem Yilmaz', 85002),
('', 85003);

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Genre`
--

CREATE TABLE `Genre` (
  `Name` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `Genre`
--

INSERT INTO `Genre` (`Name`) VALUES
(''),
('Adventure'),
('Comedy'),
('Comedy Drama'),
('Documentary'),
('Drama'),
('Horror'),
('Melodrama'),
('Musical'),
('Romantic Comedy'),
('Science Fiction'),
('Teen'),
('Thriller');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Genre_Of`
--

CREATE TABLE `Genre_Of` (
  `Name` varchar(20) NOT NULL,
  `MovieID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `Genre_Of`
--

INSERT INTO `Genre_Of` (`Name`, `MovieID`) VALUES
('Adventure', 1),
('Comedy', 13),
('Drama', 9),
('Drama', 12),
('Melodrama', 3),
('Musical', 3),
('Science Fiction', 1),
('Science Fiction', 5),
('Science Fiction', 6),
('Science Fiction', 7),
('Science Fiction', 8),
('Teen', 2),
('Thriller', 11);

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Movie`
--

CREATE TABLE `Movie` (
  `MovieID` int(11) NOT NULL,
  `ReleaseDate` int(11) DEFAULT NULL,
  `Title` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `Movie`
--

INSERT INTO `Movie` (`MovieID`, `ReleaseDate`, `Title`) VALUES
(1, 2014, 'Interstellar'),
(2, 2004, 'Mean Girls'),
(3, 2016, 'La La Land'),
(5, 2006, 'The Prestige'),
(6, 2010, 'Inception'),
(7, 2021, 'Dune'),
(8, 2011, 'In Time'),
(9, 2014, 'Whiplash'),
(11, 2012, 'The Hunger Games'),
(12, 1999, 'The Green Mile'),
(13, 2004, 'GORA');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Participant`
--

CREATE TABLE `Participant` (
  `DateOfBirth` date DEFAULT NULL,
  `Username` varchar(50) DEFAULT NULL,
  `UserID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `Participant`
--

INSERT INTO `Participant` (`DateOfBirth`, `Username`, `UserID`) VALUES
('2000-08-22', 'yunuskrt', 12345),
('1998-12-14', 'fkaanyalcin', 25003),
('2000-05-31', 'valeriacasagrande', 26237),
('2000-03-26', 'edakarabudak', 26590),
('1999-09-07', 'ahsenihamza', 26636),
('2000-06-22', 'asumanasli', 26819),
('2000-08-22', 'yunustankerestecioglu', 28168);

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Produced`
--

CREATE TABLE `Produced` (
  `MovieID` int(11) NOT NULL,
  `ProID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `Produced`
--

INSERT INTO `Produced` (`MovieID`, `ProID`) VALUES
(1, 13023),
(2, 17777),
(3, 15039),
(5, 13023),
(6, 13023),
(7, 11002),
(8, 12002),
(9, 16754),
(11, 11093),
(12, 12345),
(13, 17778);

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Producer`
--

CREATE TABLE `Producer` (
  `ProducerName` varchar(25) DEFAULT NULL,
  `ProID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `Producer`
--

INSERT INTO `Producer` (`ProducerName`, `ProID`) VALUES
('Mary Parent', 11002),
('Nina Jacobson', 11093),
('Marc E. Platt', 12001),
('Andrew Niccol', 12002),
('David Valdes', 12345),
('Emma Thomas', 13023),
('Fred Berger', 15039),
('Denis Villeneuve', 16666),
('Jason Blum', 16754),
('Lorne Michaels', 17777),
('CMYLMZ', 17778),
('', 17779);

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Rate`
--

CREATE TABLE `Rate` (
  `UserID` int(11) NOT NULL,
  `NumericRating` double DEFAULT NULL,
  `MovieID` int(11) NOT NULL,
  `RateDate` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `Rate`
--

INSERT INTO `Rate` (`UserID`, `NumericRating`, `MovieID`, `RateDate`) VALUES
(25003, 3.3, 2, '2004-12-12'),
(25003, 3.4, 11, '2012-02-29'),
(26237, 5, 12, '1999-03-21'),
(26590, 4.5, 3, '2016-03-21'),
(26636, 4.9, 1, '2014-05-12'),
(26636, 4.7, 5, '2006-04-04'),
(26819, 4.8, 6, '2010-11-21'),
(26819, 3.2, 7, '2021-02-23'),
(28168, 3.2, 5, '2022-06-16'),
(28168, 4, 8, '2011-06-22'),
(28168, 2.2, 9, '2014-10-31');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `Rating`
--

CREATE TABLE `Rating` (
  `NumericRating` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Tablo döküm verisi `Rating`
--

INSERT INTO `Rating` (`NumericRating`) VALUES
(0),
(0.1),
(0.2),
(0.3),
(0.4),
(0.5),
(0.6),
(0.7),
(0.8),
(0.9),
(1),
(1.1),
(1.2),
(1.3),
(1.4),
(1.5),
(1.6),
(1.7),
(1.8),
(1.9),
(2),
(2.1),
(2.2),
(2.3),
(2.4),
(2.5),
(2.6),
(2.7),
(2.8),
(2.9),
(3),
(3.1),
(3.2),
(3.3),
(3.4),
(3.5),
(3.6),
(3.7),
(3.8),
(3.9),
(4),
(4.1),
(4.2),
(4.3),
(4.4),
(4.5),
(4.6),
(4.7),
(4.8),
(4.9),
(5);

--
-- Dökümü yapılmış tablolar için indeksler
--

--
-- Tablo için indeksler `Acted_In`
--
ALTER TABLE `Acted_In`
  ADD PRIMARY KEY (`MovieID`,`ActorID`),
  ADD KEY `ActorID` (`ActorID`);

--
-- Tablo için indeksler `Actor`
--
ALTER TABLE `Actor`
  ADD PRIMARY KEY (`ActorID`);

--
-- Tablo için indeksler `Directed`
--
ALTER TABLE `Directed`
  ADD PRIMARY KEY (`MovieID`,`DirID`),
  ADD KEY `DirID` (`DirID`);

--
-- Tablo için indeksler `Director`
--
ALTER TABLE `Director`
  ADD PRIMARY KEY (`DirID`);

--
-- Tablo için indeksler `Genre`
--
ALTER TABLE `Genre`
  ADD PRIMARY KEY (`Name`);

--
-- Tablo için indeksler `Genre_Of`
--
ALTER TABLE `Genre_Of`
  ADD PRIMARY KEY (`Name`,`MovieID`),
  ADD KEY `MovieID` (`MovieID`);

--
-- Tablo için indeksler `Movie`
--
ALTER TABLE `Movie`
  ADD PRIMARY KEY (`MovieID`);

--
-- Tablo için indeksler `Participant`
--
ALTER TABLE `Participant`
  ADD PRIMARY KEY (`UserID`);

--
-- Tablo için indeksler `Produced`
--
ALTER TABLE `Produced`
  ADD PRIMARY KEY (`MovieID`,`ProID`),
  ADD KEY `ProID` (`ProID`);

--
-- Tablo için indeksler `Producer`
--
ALTER TABLE `Producer`
  ADD PRIMARY KEY (`ProID`);

--
-- Tablo için indeksler `Rate`
--
ALTER TABLE `Rate`
  ADD PRIMARY KEY (`UserID`,`MovieID`),
  ADD KEY `NumericRating` (`NumericRating`),
  ADD KEY `MovieID` (`MovieID`);

--
-- Tablo için indeksler `Rating`
--
ALTER TABLE `Rating`
  ADD PRIMARY KEY (`NumericRating`);

--
-- Dökümü yapılmış tablolar için AUTO_INCREMENT değeri
--

--
-- Tablo için AUTO_INCREMENT değeri `Actor`
--
ALTER TABLE `Actor`
  MODIFY `ActorID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=55046;

--
-- Tablo için AUTO_INCREMENT değeri `Director`
--
ALTER TABLE `Director`
  MODIFY `DirID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=85004;

--
-- Tablo için AUTO_INCREMENT değeri `Movie`
--
ALTER TABLE `Movie`
  MODIFY `MovieID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- Tablo için AUTO_INCREMENT değeri `Participant`
--
ALTER TABLE `Participant`
  MODIFY `UserID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=28169;

--
-- Tablo için AUTO_INCREMENT değeri `Producer`
--
ALTER TABLE `Producer`
  MODIFY `ProID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17780;

--
-- Dökümü yapılmış tablolar için kısıtlamalar
--

--
-- Tablo kısıtlamaları `Acted_In`
--
ALTER TABLE `Acted_In`
  ADD CONSTRAINT `acted_in_ibfk_1` FOREIGN KEY (`MovieID`) REFERENCES `Movie` (`MovieID`),
  ADD CONSTRAINT `acted_in_ibfk_2` FOREIGN KEY (`ActorID`) REFERENCES `Actor` (`ActorID`);

--
-- Tablo kısıtlamaları `Directed`
--
ALTER TABLE `Directed`
  ADD CONSTRAINT `directed_ibfk_1` FOREIGN KEY (`MovieID`) REFERENCES `Movie` (`MovieID`),
  ADD CONSTRAINT `directed_ibfk_2` FOREIGN KEY (`DirID`) REFERENCES `Director` (`DirID`);

--
-- Tablo kısıtlamaları `Genre_Of`
--
ALTER TABLE `Genre_Of`
  ADD CONSTRAINT `genre_of_ibfk_1` FOREIGN KEY (`Name`) REFERENCES `Genre` (`Name`),
  ADD CONSTRAINT `genre_of_ibfk_2` FOREIGN KEY (`MovieID`) REFERENCES `Movie` (`MovieID`);

--
-- Tablo kısıtlamaları `Produced`
--
ALTER TABLE `Produced`
  ADD CONSTRAINT `produced_ibfk_1` FOREIGN KEY (`MovieID`) REFERENCES `Movie` (`MovieID`),
  ADD CONSTRAINT `produced_ibfk_2` FOREIGN KEY (`ProID`) REFERENCES `Producer` (`ProID`);

--
-- Tablo kısıtlamaları `Rate`
--
ALTER TABLE `Rate`
  ADD CONSTRAINT `rate_ibfk_1` FOREIGN KEY (`UserID`) REFERENCES `Participant` (`UserID`),
  ADD CONSTRAINT `rate_ibfk_2` FOREIGN KEY (`NumericRating`) REFERENCES `Rating` (`NumericRating`),
  ADD CONSTRAINT `rate_ibfk_3` FOREIGN KEY (`MovieID`) REFERENCES `Movie` (`MovieID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
