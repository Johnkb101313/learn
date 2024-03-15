Information is come from: [lucidchart](https://www.lucidchart.com/pages/er-diagrams)  
ER Diagrams are composed of entities, relationships and attributes. They also depict cardinality, which defines relationships in terms of numbers.  
Here’s a glossary:

### Entity
A definable thing—such as a person, object, concept or event—that can have data stored about it.  
Examples: a customer, student, car or product.  
Typically shown as a **rectangle**.

![](src/img/ER_Entity_symbol.svg "ER Entity symbol")

##### Entity type:
A group of definable things, such as students, whereas the entity would be the specific student.

##### Entity set:
Same as an entity type, but defined at a particular point in time, such as students enrolled in a class on the first day.  
Other examples: Customers who purchased last month.  
A related term is instance, in which the specific person would be an instance of the entity set.


##### Entity categories:
Entities are categorized as **strong**, **weak** or **associative**. A **strong entity** can be defined solely by its own attributes, while a **weak entity cannot**. An **associative entity** associates entities (or elements) within an entity set.
![](src/img/ER_Associative_Entity_symbol.svg "ER Associative Entity symbol")

##### Entity keys:
Refers to an attribute that uniquely defines an entity in an entity set.  
Entity keys can be **super**, **candidate** or **primary**.  
**Super key**: A set of attributes (one or more) that together define an entity in an entity set.  
**Candidate key**: A minimal super key, meaning it has the least possible number of attributes to still be a super key. An entity set may have more than one candidate key.  
**Primary key**: A candidate key chosen by the database designer to uniquely identify the entity set.  
**Foreign key**: Identifies the relationship between entities.  

Student (Entity)  
Students (Entity Type)  
Students on event (Entity Set: **Students**, an Entity in Entity Set is called **Instance**, without event this will called Entity Type, not Entity)  

---

