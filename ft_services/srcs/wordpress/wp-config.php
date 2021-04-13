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
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wp_db' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', 'admin' );

/** MySQL hostname */
define( 'DB_HOST', '10.98.112.191' );

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
define( 'AUTH_KEY',         'G6_vDOL:Z[;R&;lamq$Io9D[He}{Y&_g5fc<@GA.gs3[2iUx|X$hPPfx-H9( 9lr' );
define( 'SECURE_AUTH_KEY',  '+oe0{Kg(0ko<>wp0gt.DRI(+Yn^ef-4QHXc*g$:s$,`|,i0w]3D)n kFL,jwZ7A?' );
define( 'LOGGED_IN_KEY',    'x/,uztI(q(Be|mY<R,[<o{}-e%9K5&4BLjZ$xrkJ.Du2*]rAV0R~txLs#^eN.r.k' );
define( 'NONCE_KEY',        '@uMLc~f.Xgp9]t}heS`g=ZGv++AyT]j35KAkREZRbw~8-cW/au^Ksi?$3FSaYT>:' );
define( 'AUTH_SALT',        'm}am/gnkTPgtEvOoGTvxC)S%6a0QW>7%i[;<@} $O6xf>^%GgZzZ7(#[-a~p@c;Y' );
define( 'SECURE_AUTH_SALT', 'Sbg%Ix#$02&X*uYa<}+<qYy!VbH[_$,u* _x5q?5{^]Pi{T@,h*N@3XV{HLQ0)dH' );
define( 'LOGGED_IN_SALT',   'g$U{zX,ZVVbQb)|$g>X<0ohAMR+aN@ox`lKsj=Ncy}!M15])?VZ~. rqdqxgaWcm' );
define( 'NONCE_SALT',       ',0gk`5Ei3qvNOxPS^JIq5wF5z+ *tm0Et,R%7XtLR*gzg37tkYnkKY=9jU C.W{t' );

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
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';