# order-management-system  
Coursework (2/2) for module ECM2433  
## Scenario  
Customer's place multiple orders during each day.  
At the end of each day the orders are collated and each customer’s total order quantity is sent to them as a single shipment.  
If a customer places an “express” order, then it and all its outstanding orders for the day are sent immediately (bypasses end of day).  
When a shipment is triggered for a customer, they are notified that a shipment is on its way, and an invoice is sent to them.  
  
## Task TODO List
Each checkbox represents...
 * [ ] To be implemented
 * [x] Implementation complete

___
### Test For Memory Leaks (Valgrind)
Command Line: `valgrind -s --leak-check=yes bin/./ordering testInputFile.txt`
 * [x] All memory leaks resolved

### Handling the Input File
 * [x] read CL parameters (for the file name)
 * [x] process data for...
   - new customers
   - sales orders
   - end-of-day

### Using the Input Data
Sales order records can be normal or express orders.  
Each record results in one of 4 following actions:  
Add a new...
 * [x] customer (with unique id)
 * [x] "normal" order :
   - quantity is added to the customer's order total
 * [x] express order :
   - quantity is added to the customer's order total,
   - then; total quantity is shipped to the customer,
   - finally; the customer's order quantity is then reset to 0.
 * [x] End-of-day processing :
   - ( only for customers who have orders > 0 )
   - total quantity is shipped to the customer,
   - then; the customer's order quantity is then reset to 0.

### Handling Output
Messages are sent to the output stream.  
The following prefix delcares the messages were generated from...
 * [x] OP: the order processing system
 * [x] SC: a customer

A message will be generated for each event...
 * [x] new customer is added
 * [x] new normal order is processed
 * [x] new express order is processed
 * [x] shipment is sent to a customer
 * [x] end of a day has been reached
 * [x] (customer message) customer receives an invoice

### Input File Regex (Records)
  
#### Example Input File
| Line   | Contents                             | 
| --:    | :--                                  |
| 1      | C0001Royal Devon & Exeter Hospital   |
| 2      | C0002Derriford Hospital              |
| 3      | C0003Torbay Hospital                 |
| 4      | S20210201N0001040                    |
| 5      | S20210201N0001050                    |
| 6      | E20210201                            |
| 7      | S20210202N0001040                    |
| 8      | S20210202N0001060                    |
| 9      | S20210202N0002050                    |
| 10     | S20210202N0002170                    |
| 11     | E20210202                            |
| 12     | S20210203N0001050                    |
| 13     | S20210203N0002065                    |
| 14     | S20210203N0003150                    |
| 15     | S20210203X0001190                    |
| 16     | S20210203N0002110                    |
| 17     | E20210203                            |
  
#### New Customer
| Column | Datatype  | Description                                   |
| --:    | :-:       | :--                                           |
| 1      | char      | start with 'C'                                |
| 2-5    | int       | customer number; a four digit, zero-padded    |
| 6-45   | string    | customer’s name                               |

#### Sales Order
| Column | Datatype  | Description                                   |
| --:    | :-:       | :--                                           |
| 1      | char      | start with 'S'                                |
| 2-9    | int       | order date (YYYYMMDD)                         |
| 10     | char      | 'N' = normal order; 'X' = express order       |
| 11-14  | int       | customer number (customer raising the order)  |
| 15-17  | int       | order quantity; three-digits, zero-padded     |

#### End-of-day
| Column | Datatype  | Description                                   |
| --:    | :-:       | :--                                           |
| 1      | char      | start with 'E'                                |
| 2-9    | int       | date (YYYYMMDD); marks the end of the day     |
  
___
## Deliverables
( C++11 )
 * [x] Linux Shell compile script called "compileOP"
 * [x] compiled executable must be called "ordering"
 * [ ] Report

 ## Report
 - 3 pages (Max)
 - Must describe:
   - overall design
   - how classes support the fnctionality
   - assumptions made
   - (only if code does not work)
     - the testing performed to find the problem
