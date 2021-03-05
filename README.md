# order-management-system  
## Scenario
Each customer places multiple orders during each day.  
At the end of each day the orders are collatedand each customer’s total order quantity is sent to them as a single shipment.  
If a customer placesan “express” order, then it and all its outstanding orders for the day are sent immediately (i.e.  notwaiting for the end of the day).  
When a shipment is triggered for a customer, they are notified that a shipment is on its way, andan invoice is sent to them.  
___  
## Task TODO List  
Each checkbox represents...  
 * [ ] Code to be implemented  
 * [X] Implementation complete  
  
### Handling the Input File  
 1. * [ ] read CL parameters (for the file name)
 2. * [ ] process data for...  
    - new customers  
    - sales orders  
    - end-of-day  
### Using the Input Data
Sales order records can be normal or express orders.  
Each record results in one of 4 following actions:  
Add a new...  
 1. * [ ] customer (with unique id)  
 2. * [ ] "normal" order :  
    - quantity is added to the customer's order total
 3. * [ ] express order :  
    - quantity is added to the customer's order total, 
    - then; total quantity is shipped to the customer,
    - finally; the customer's order quantity is then reset to 0.  
 4. * [ ] End-of-day processing :  
    - ( only for customers still have orders (> 0) )
    - total quantity is shipped to the customer,
    - then; the customer's order quantity is then reset to 0. 

### Handling Output  
Messages are sent to the output stream.  
The following prefix delcares the messages were generated from...  
   - * [ ] OP: the order processing system  
   - * [ ] SC: a customer  
  
A message will be generated for each event...
 -  * [ ] new customer is added
 -  * [ ] new normal order is processed
 -  * [ ] new express order is processed
 -  * [ ] shipment is sent to a customer
 -  * [ ] end of a day has been reached
___  
## Deliverables  
( C++11 )  
 1. * [ ] Linux Shell compile script called "compileOP"
    - compiled executable must be called "ordering"
 2. * [ ] Report

 ## Report
 - 3 pages (Max)
 - Must describe:
   - overall design
   - how classes support the fnctionality
   - assumptions made
   - (only if code does not work)
     - the testing performed to find the problem
