CC = g++
CFLAGS = -std=c++11

SRC_DIR = src
BUILD_DIR = build
EXECUTABLE_FILE = a.out

OBJECTS = $(BUILD_DIR)/main.o \
		  $(BUILD_DIR)/Interface.o \
		  $(BUILD_DIR)/Tools.o \
		  $(BUILD_DIR)/JomeBazaar.o \
		  $(BUILD_DIR)/API.o \
		  $(BUILD_DIR)/User.o \
		  $(BUILD_DIR)/Product.o \
		  $(BUILD_DIR)/UserRepository.o \
		  $(BUILD_DIR)/ProductRepository.o \
		  $(BUILD_DIR)/Offer.o \
		  $(BUILD_DIR)/Discount.o \
		  $(BUILD_DIR)/Seller.o \
		  $(BUILD_DIR)/Wallet.o \
		  $(BUILD_DIR)/Buyer.o \
		  $(BUILD_DIR)/Admin.o


.PHONY: all build_objects make_build_dir clean

all: make_build_dir build_objects

build_objects: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE_FILE)

make_build_dir:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) *.o *.out


mainHeaderSensitivities = $(InterfaceHeaderSensitivities)

InterfaceHeaderSensitivities = $(SRC_DIR)/Interface.hpp \
							   $(SRC_DIR)/Exception.hpp \
							   $(SRC_DIR)/Exceptions.hpp \
							   $(SRC_DIR)/constants.hpp \
							   $(SRC_DIR)/Tools.hpp \
							   $(SRC_DIR)/JomeBazaar.hpp

ToolsHeaderSensitivities = $(SRC_DIR)/Tools.hpp

JomeBazaarHeaderSensitivities = $(SRC_DIR)/JomeBazaar.hpp \
								$(SRC_DIR)/API.hpp \
								$(SRC_DIR)/User.hpp \
								$(SRC_DIR)/UserRepository.hpp \
								$(SRC_DIR)/ProductRepository.hpp \
								$(SRC_DIR)/constants.hpp \
								$(SRC_DIR)/Buyer.hpp \
								$(SRC_DIR)/Seller.hpp \
								$(SRC_DIR)/Tools.hpp \
								$(SRC_DIR)/Exceptions.hpp \
								$(SRC_DIR)/Admin.hpp

APIHeaderSensitivities = $(SRC_DIR)/API.hpp \
						 $(SRC_DIR)/UserRepository.hpp \
						 $(SRC_DIR)/ProductRepository.hpp

UserHeaderSensitivities = $(SRC_DIR)/User.hpp \
						  $(SRC_DIR)/API.hpp

ProductHeaderSensitivities = $(SRC_DIR)/Product.hpp \
						     $(SRC_DIR)/Offer.hpp

UserRepositoryHeaderSensitivities = $(SRC_DIR)/UserRepository.hpp \
									$(SRC_DIR)/User.hpp \
									$(SRC_DIR)/constants.hpp

ProductRepositoryHeaderSensitivities =  $(SRC_DIR)/ProductRepository.hpp \
										$(SRC_DIR)/Offer.hpp \
										$(SRC_DIR)/Product.hpp \
										$(SRC_DIR)/Discount.hpp

OfferHeaderSensitivities = $(SRC_DIR)/Offer.hpp \
						   $(SRC_DIR)/Discount.hpp \
						   $(SRC_DIR)/Seller.hpp

DiscountHeaderSensitivities = $(SRC_DIR)/Discount.hpp \
							  $(SRC_DIR)/constants.hpp

SellerHeaderSensitivities = $(SRC_DIR)/Seller.hpp \
							$(SRC_DIR)/User.hpp \
							$(SRC_DIR)/Wallet.hpp \
							$(SRC_DIR)/Product.hpp \
							$(SRC_DIR)/API.hpp \
							$(SRC_DIR)/Tools.hpp \
							$(SRC_DIR)/Offer.hpp \
							$(SRC_DIR)/Discount.hpp 

WalletHeaderSensitivities = $(SRC_DIR)/Wallet.hpp

BuyerHeaderSensitivities = $(SRC_DIR)/Buyer.hpp \
						   $(SRC_DIR)/User.hpp \
						   $(SRC_DIR)/Wallet.hpp \
						   $(SRC_DIR)/Offer.hpp \
						   $(SRC_DIR)/Factor.hpp \
						   $(SRC_DIR)/CartItem.hpp \
						   $(SRC_DIR)/constants.hpp

AdminHeaderSensitivities = $(SRC_DIR)/Admin.hpp \
						   $(SRC_DIR)/User.hpp \
						   $(SRC_DIR)/constants.hpp

mainSensitivityList = $(SRC_DIR)/main.cpp \
					  $(mainHeaderSensitivities)

InterfaceSensitivityList = $(SRC_DIR)/Interface.cpp \
						   $(InterfaceHeaderSensitivities) \

ToolsSensitivityList = $(SRC_DIR)/Tools.cpp \
					   $(ToolsHeaderSensitivities)

JomeBazaarSensitivityList = $(SRC_DIR)/JomeBazaar.cpp \
					        $(JomeBazaarHeaderSensitivities)

APISensitivityList = $(SRC_DIR)/API.cpp \
					 $(APIHeaderSensitivities)

UserSensitivityList = $(SRC_DIR)/User.cpp \
					  $(UserHeaderSensitivities)

ProductSensitivityList = $(SRC_DIR)/Product.cpp \
					  $(ProductHeaderSensitivities)

UserRepositorySensitivityList = $(SRC_DIR)/UserRepository.cpp \
								$(UserRepositoryHeaderSensitivities)

ProductRepositorySensitivityList = $(SRC_DIR)/ProductRepository.cpp \
								   $(ProductRepositoryHeaderSensitivities)

OfferSensitivityList = $(SRC_DIR)/Offer.cpp \
					   $(OfferHeaderSensitivities)

DiscountSensitivityList = $(SRC_DIR)/Discount.cpp \
					      $(DiscountHeaderSensitivities)

SellerSensitivityList = $(SRC_DIR)/Seller.cpp \
					    $(SellerHeaderSensitivities)
						  
WalletSensitivityList = $(SRC_DIR)/Wallet.cpp \
					      $(WalletHeaderSensitivities)

BuyerSensitivityList = $(SRC_DIR)/Buyer.cpp \
					      $(BuyerHeaderSensitivities)

AdminSensitivityList = $(SRC_DIR)/Admin.cpp \
					      $(AdminHeaderSensitivities)

$(BUILD_DIR)/main.o: $(mainSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/Interface.o: $(InterfaceSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Interface.cpp -o $(BUILD_DIR)/Interface.o

$(BUILD_DIR)/Tools.o: $(ToolsSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Tools.cpp -o $(BUILD_DIR)/Tools.o

$(BUILD_DIR)/JomeBazaar.o: $(JomeBazaarSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/JomeBazaar.cpp -o $(BUILD_DIR)/JomeBazaar.o

$(BUILD_DIR)/API.o: $(APISensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/API.cpp -o $(BUILD_DIR)/API.o

$(BUILD_DIR)/User.o: $(UserSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/User.cpp -o $(BUILD_DIR)/User.o

$(BUILD_DIR)/Product.o: $(ProductSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Product.cpp -o $(BUILD_DIR)/Product.o

$(BUILD_DIR)/UserRepository.o: $(UserRepositorySensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/UserRepository.cpp -o $(BUILD_DIR)/UserRepository.o

$(BUILD_DIR)/ProductRepository.o: $(ProductRepositorySensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ProductRepository.cpp -o $(BUILD_DIR)/ProductRepository.o

$(BUILD_DIR)/Offer.o: $(OfferSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Offer.cpp -o $(BUILD_DIR)/Offer.o

$(BUILD_DIR)/Discount.o: $(DiscountSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Discount.cpp -o $(BUILD_DIR)/Discount.o

$(BUILD_DIR)/Seller.o: $(SellerSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Seller.cpp -o $(BUILD_DIR)/Seller.o

$(BUILD_DIR)/Wallet.o: $(WalletSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Wallet.cpp -o $(BUILD_DIR)/Wallet.o

$(BUILD_DIR)/Buyer.o: $(BuyerSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Buyer.cpp -o $(BUILD_DIR)/Buyer.o

$(BUILD_DIR)/Admin.o: $(AdminSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Admin.cpp -o $(BUILD_DIR)/Admin.o