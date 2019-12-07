#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#define OK "OK"
#define BAD_REQUEST "Bad Request"
#define SUCCESS true
#define FAILED false
#define ADMIN_USERNAME "ADMIN"
#define ADMIN_PASSWORD "ADMIN"
#define SEPERATOR " | "
#define POST "POST"
#define GET "GET"
#define MIN_COMMAND_SIZE 2

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