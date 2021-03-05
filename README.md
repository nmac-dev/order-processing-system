# order-management-system  
Coursework (2/2) for module ECM2433  
## Scenario  
Customer's place multiple orders during each day.  
At the end of each day the orders are collated and each customer’s total order quantity is sent to them as a single shipment.  
If a customer placesan “express” order, then it and all its outstanding orders for the day are sent immediately (i.e.  notwaiting for the end of the day).  
When a shipment is triggered for a customer, they are notified that a shipment is on its way, andan invoice is sent to them.  

## Task TODO List
Each checkbox represents...
 * [ ] Code to be implemented
 * [x] Implementation complete
___
### Handling the Input File
 * [ ] read CL parameters (for the file name)
 * [ ] process data for...
   - new customers
   - sales orders
   - end-of-day

### Using the Input Data
Sales order records can be normal or express orders.  
Each record results in one of 4 following actions:  
Add a new...
 * [ ] customer (with unique id)
 * [ ] "normal" order :
   - quantity is added to the customer's order total
 * [ ] express order :
   - quantity is added to the customer's order total,
   - then; total quantity is shipped to the customer,
   - finally; the customer's order quantity is then reset to 0.
 * [ ] End-of-day processing :
   - ( only for customers who have orders > 0 )
   - total quantity is shipped to the customer,
   - then; the customer's order quantity is then reset to 0.

### Handling Output
Messages are sent to the output stream.  
The following prefix delcares the messages were generated from...
 * [ ] OP: the order processing system
 * [ ] SC: a customer

A message will be generated for each event...
 * [ ] new customer is added
 * [ ] new normal order is processed
 * [ ] new express order is processed
 * [ ] shipment is sent to a customer
 * [ ] end of a day has been reached
 * [ ] (customer message) customer receives an invoice

### Output Regex for Records  
  
#### New Customer
| Column | Datatype  | Description                                   |
| --:    | :-:       | :--                                           |
| 1      | char      | C                                             |
| 2-5    | int       | customer number; a four digit, zero-padded    |
| 6-45   | string    | customer’s name                               |

#### Sales Order
| Column | Datatype  | Description                                   |
| --:    | :-:       | :--                                           |
| 1      | char      | 'S'                                           |
| 2-9    | int       | order date (YYYYMMDD)                         |
| 10     | char      | 'N' = normal order; 'X' = express order       |
| 11-14  | int       | customer number (customer raising the order)  |
| 15-17  | int       | order quantity; three-digits, zero-padded     |

#### End-of-day
| Column | Datatype  | Description                                   |
| --:    | :-:       | :--                                           |
| 1      | char      | 'E'                                           |
| 2-9    | int       | date (YYYYMMDD); marks the end of the day     |

___
## Deliverables
( C++11 )
 * [ ] Linux Shell compile script called "compileOP"
 * [ ] compiled executable must be called "ordering"
 * [ ] Report

 ## Report
 - 3 pages (Max)
 - Must describe:
   - overall design
   - how classes support the fnctionality
   - assumptions made
   - (only if code does not work)
     - the testing performed to find the problem
