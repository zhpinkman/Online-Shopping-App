#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#define OK "OK"
#define BAD_REQUEST "Bad Request"
#define SUCCESS true
#define FAILED false
#define SEPERATOR " | "
#define POST "POST"
#define GET "GET"
#define MIN_COMMAND_SIZE 2
#define USER_ID_BEGIN 1
#define ADMIN_USERNAME "admin"
#define ADMIN_PASSWORD "admin"
#define ADMIN_EMAIL "admin@gmail.com"

#define SIGNUP "signup"
#define LOGIN "login"
#define LOGOUT "logout"
#define IMPORT_PRODUCT "importProduct"
#define OFFERS "offers"
#define GET_PRODUCTS "getProducts"
#define OFFER "offer"
#define MY_OFFERS "myOffers"
#define CHANGE_OFFER "changeOffer"
#define WALLET "wallet"
#define GENERATE_DISCOUNT_CODE "generateDiscountCode"
#define OFFERS_ON_PRODUCT "offersOnProduct"
#define PRODUCT_DETAIL "productDetail"
#define COMMENTS "comments"
#define ADD_TO_CART "addToCart"
#define CART "cart"
#define SUBMIT_CART "submitCart"
#define ORDERS "orders"
#define CHANGE_WALLET "changeWallet"
#define COMMENT "comment"
#define COMPARE "compare"
#define OFFER_BUYERS "offerBuyers"

#define SIGNUP_MAX_SIZE 11
#define SELLER_STR "seller"
#define BUYER_STR "buyer"

#define MOBILE_TYPE "mobile"
#define TV_TYPE "tv"
#define CAR_TYPE "car"

#define SPACE ' '
#define COMMA ','

#define OUTPUT_SEPARATOR " | "
#define PRODUCT_ID "productId"
#define PRODUCT_NAME "productName"
#define OFFER_ID "offerId"
#define OFFER_UNIT_PRICE "offerUnitPrice"
#define OFFER_AMOUNT "offerAmount"
#define OFFER_PRICE "offerPrice"

#define ASCEND "ASCEND"
#define DESCEND "DESCEND"

enum UserType
{
    BUYER,
    SELLER,
};

enum DiscountStatus
{
    USED,
    UNUSED
};

#endif