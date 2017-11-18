-- phpMyAdmin SQL Dump
-- version 4.7.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Nov 18, 2017 at 05:58 AM
-- Server version: 5.7.19
-- PHP Version: 5.6.31

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `tsarbucks`
--
CREATE DATABASE IF NOT EXISTS `tsarbucks` DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;
USE `tsarbucks`;

-- --------------------------------------------------------

--
-- Table structure for table `cart`
--

DROP TABLE IF EXISTS `cart`;
CREATE TABLE IF NOT EXISTS `cart` (
  `product_id` int(11) NOT NULL,
  `quantity` int(11) NOT NULL,
  PRIMARY KEY (`product_id`),
  UNIQUE KEY `product_id` (`product_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `orders`
--

DROP TABLE IF EXISTS `orders`;
CREATE TABLE IF NOT EXISTS `orders` (
  `order_id` int(10) UNSIGNED NOT NULL,
  `user_id` int(10) NOT NULL,
  `product_id` int(10) NOT NULL,
  `quantity` int(10) NOT NULL,
  `completed` tinyint(1) NOT NULL DEFAULT '0',
  `created_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated_at` timestamp NULL DEFAULT NULL,
  PRIMARY KEY (`order_id`,`user_id`,`product_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `orders`
--

INSERT INTO `orders` (`order_id`, `user_id`, `product_id`, `quantity`, `completed`, `created_at`, `updated_at`) VALUES
(1, 1, 1, 2, 1, '2017-11-05 06:56:05', NULL),
(1, 1, 2, 4, 1, '2017-11-05 06:56:05', NULL),
(1, 1, 3, 1, 1, '2017-11-05 06:56:05', NULL),
(2, 1, 2, 5, 1, '2017-11-05 06:56:05', NULL),
(2, 1, 5, 2, 1, '2017-11-05 06:56:05', NULL),
(3, 1, 4, 1, 1, '2017-11-05 06:56:05', NULL),
(4, 1, 8, 1, 1, '2017-11-05 06:56:05', NULL),
(4, 1, 6, 3, 1, '2017-11-05 06:56:05', NULL),
(5, 1, 7, 2, 1, '2017-11-05 06:56:05', NULL),
(6, 1, 3, 4, 1, '2017-11-05 06:56:05', NULL),
(7, 1, 1, 1, 1, '2017-11-16 09:49:00', NULL),
(7, 1, 2, 1, 1, '2017-11-16 09:49:00', NULL),
(7, 1, 3, 1, 1, '2017-11-16 09:49:00', NULL),
(8, 1, 2, 1, 1, '2017-11-16 09:49:10', NULL),
(8, 1, 3, 1, 1, '2017-11-16 09:49:10', NULL),
(8, 1, 4, 1, 1, '2017-11-16 09:49:10', NULL),
(8, 1, 8, 1, 1, '2017-11-16 09:49:10', NULL),
(8, 1, 7, 1, 1, '2017-11-16 09:49:10', NULL),
(9, 1, 5, 1, 1, '2017-11-16 09:50:09', NULL),
(9, 1, 8, 1, 1, '2017-11-16 09:50:09', NULL),
(9, 1, 7, 1, 1, '2017-11-16 09:50:09', NULL),
(10, 4, 2, 3, 1, '2017-11-18 02:55:01', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `products`
--

DROP TABLE IF EXISTS `products`;
CREATE TABLE IF NOT EXISTS `products` (
  `product_id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `display_name` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `price` decimal(4,2) NOT NULL,
  `size` tinyint(2) NOT NULL COMMENT 'size in ounces',
  `created_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated_at` timestamp NULL DEFAULT NULL,
  PRIMARY KEY (`product_id`)
) ENGINE=MyISAM AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `products`
--

INSERT INTO `products` (`product_id`, `display_name`, `price`, `size`, `created_at`, `updated_at`) VALUES
(1, 'Black Coffee (Small)', '5.00', 2, '2017-11-05 06:56:05', NULL),
(2, 'Black Coffee (Medium)', '7.50', 4, '2017-11-05 06:56:05', NULL),
(3, 'Black Coffee (Large)', '10.00', 8, '2017-11-05 06:56:05', NULL),
(4, 'Espresso (Small)', '6.00', 1, '2017-11-05 06:56:05', NULL),
(5, 'Espresso (Large)', '12.00', 2, '2017-11-05 06:56:05', NULL),
(6, 'Tsartisan Coffee (Small)', '10.00', 4, '2017-11-05 06:56:05', NULL),
(7, 'Tsartisan Coffee (Large)', '20.00', 8, '2017-11-05 06:56:05', NULL),
(8, 'Plum Floating in Perfume, Served in a Man\'s Hat', '15.00', 16, '2017-11-05 06:56:05', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `roles`
--

DROP TABLE IF EXISTS `roles`;
CREATE TABLE IF NOT EXISTS `roles` (
  `system_name` varchar(32) COLLATE utf8_unicode_ci NOT NULL,
  `display_name` varchar(32) COLLATE utf8_unicode_ci NOT NULL,
  `created_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated_at` timestamp NULL DEFAULT NULL,
  PRIMARY KEY (`system_name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `roles`
--

INSERT INTO `roles` (`system_name`, `display_name`, `created_at`, `updated_at`) VALUES
('customer', 'Customer', '2017-11-05 06:56:05', NULL),
('barista', 'Barista', '2017-11-05 06:56:05', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
CREATE TABLE IF NOT EXISTS `users` (
  `user_id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `username` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `password` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `display_name` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `created_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated_at` timestamp NULL DEFAULT NULL,
  PRIMARY KEY (`user_id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`user_id`, `username`, `password`, `display_name`, `created_at`, `updated_at`) VALUES
(1, 'customer', 'customer', 'John', '2017-11-05 06:56:05', NULL),
(2, 'barista', 'barista', 'Matt', '2017-11-05 06:56:05', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `user_roles`
--

DROP TABLE IF EXISTS `user_roles`;
CREATE TABLE IF NOT EXISTS `user_roles` (
  `user_id` int(10) UNSIGNED NOT NULL,
  `role` varchar(32) COLLATE utf8_unicode_ci NOT NULL,
  `created_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `updated_at` timestamp NULL DEFAULT NULL,
  PRIMARY KEY (`user_id`,`role`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `user_roles`
--

INSERT INTO `user_roles` (`user_id`, `role`, `created_at`, `updated_at`) VALUES
(1, 'customer', '2017-11-05 06:56:05', NULL),
(2, 'barista', '2017-11-05 06:56:05', NULL);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
