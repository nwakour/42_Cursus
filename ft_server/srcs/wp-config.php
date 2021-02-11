<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', 'admin' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '9?&L2>Fn9<jJ~^sQMV48zX&q~*5T.)%!mrA9f/u-kt[YDCuax^;c%KuldGv(GCCv' );
define( 'SECURE_AUTH_KEY',  '[ipMD|+Y7;}1y9MpExR{_Yr-$$i(-W[y/jkr+w1kItKw7:=D.Da|E1w%SqV|jy^x' );
define( 'LOGGED_IN_KEY',    'w1M0)[bt&sC{,f|C-3)abfs>AG!5`i=A#GVcA{9+XLV%aAxf1SRt:#z:`Ia(`Bl&' );
define( 'NONCE_KEY',        '| $uU!#@E&y;,|;9Ejol_QDK)sVRHA3w?GJ*{#/TonaU14.dYkgof?;M/x!YV$,O' );
define( 'AUTH_SALT',        'lx.td=1O]Jk0a`udt[ liiN|q&tMeC7|C_YF*K( nYH]BOyj/yvV<F=#;.OnRGt.' );
define( 'SECURE_AUTH_SALT', '>G]6SyQbgN<Nxe0637:~!lZ:vTXUD^yI.=223Gm~r,:(QC1%t|m<(]~p>_M*HL)T' );
define( 'LOGGED_IN_SALT',   'gPkQR-BVLAweo^D@Qk;=};e0sEG_(}c;(pWulE`RAT`N<sY=,wjkhrAkCuPJRf,k' );
define( 'NONCE_SALT',       'u:03%%@EKA}ixj9+.EA-Cc_<!8~.C+&BWvu_Y{q1|&t:;g5*QdM^`a?hCmsi.:} ' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */

define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}


/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
