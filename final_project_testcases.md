# Testcases

## invalid commands

- invalid methods execpt **POST & GET**
- invalid command after **POST & GET**
- permission issues with commands

## registration

- signup with **OK** output
  - both with seller and buyer
- signup with bad args
- admin signup and auth
- duplicate user signup

## login

- login with **OK** output
- checking if user does not exist
- login with bad args
- double login output
- loggin in several times with different users

## logout

- logout with **OK** output
- logout with no user logged in
- loggin out with several users

## importing products

- importing from a file that does not exists
- importing with **OK** output
- importing with bad args beside wrong file

## getting products

- getting products by `getProducts` command

## add offer

- adding offer for some product and getting the **OK** output
- getting the offers list corresponding to the offers added for products

## change offer

- changing offer and checking the output for `getoffers` command

## discount code

- generating some random code and check their difference
- generating some random code and checking their count

## get offers

- checking `getoffers` and `getoffersOnProduct` output

## product detail

- checking `productDetail` command output

## cart

- adding to cart and checking its content after some addition
- adding to cart
  - with discount
  - with invalid discount
  - without discount
- submitting cart and checking the history and wallet due to the buy action
  - buyer and seller wallet
  - history of the buyer
  - available amount of the offer after buying

## wallet

- adding to wallet with `chargeWallet` and checking the balance with `getWallet`

## comparing two products
