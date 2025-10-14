# Year-End Review: Key Contributions and Achievements

---

## 1. CASS Report Development for OPS and Client Service Teams
- Documented detailed **business and technical requirements** on the **Confluence page**.
- Designed and developed a new **template** for storing **daily exposure data**, including all required **reporting columns**.
- Created **F3 jobs** and **Control-M jobs** to automate **daily report generation**.
- Developed **DSS flow service configuration** to load report data daily into the **staging table** of the **dbmarginil schema**.
- Designed and created **staging and archival tables** for **data management**.
- Implemented **stored procedure logic** to generate the **CASS report**, along with **scripts** to call the procedure for **OPS** and **Client Service teams**.
- Enhanced logic to include additional columns (e.g., **CCP, FX_RATE**) missing from the original **DER template**.
- Updated **DSS configurations**, reloaded data, and performed comprehensive **archival testing**.
- Implemented **Repgen** and **Control-M changes** to ensure smooth **report generation and scheduling**.
- Conducted a detailed **handover session** and explained all changes to **Rajesh**.

---

## 2. MCUBE Balance Report Development
- Developed **stored procedure logic** in the **dbmarginil schema** to load daily **price** and **haircut data** from **dbmargin tables**.
- Created **Control-M jobs** and **scripts** to automate the **data load process**, scheduled **Sunday–Thursday at 9:30 PM EST**, aligned with **DBREX job schedule**.
- Designed and implemented a **stored procedure** to generate the **MCUBE Balance Report**, resolving multiple **data outliers** through extensive **testing and validation**.
- Built a **Java utility** to identify and analyze **discrepancies** between **DBMargin** and **DBREX MCUBE Balance reports**.
- Collaborated closely with **Rajesh** to align reporting flows with **DBREX logic** (Informatica and PL/SQL).
- Conducted multiple **parallel production tests and deployments** to resolve **performance issues** and **data mismatches**.
- Provided **knowledge transfer (KT)** to the **MCUBE team**, incorporated their **feedback**, and obtained **final sign-off**.
- Implemented **feed enhancement** to convert **As_of_date** into `yyyy-MM-dd` format as per **MCUBE team requirements**.
- Achieved significant **performance optimization** by:
  - Aggregating **60-day-old balances** into **local tables** for faster retrieval.
  - Archiving **2-month-old price and haircut data** into **history tables**.
  - Adding **table partitioning**, reducing **report generation time** to under **12 minutes**.
  - Automating **archival** of data older than **65 business days** via **dbmarginil archival process**.

---

## 3. House Development
- Built logic in **cs-post-ingestion-service** to handle **GET HTTP requests** with **query parameters**.
- Completed deployment tasks including creation of **tables, views, types, sequences, packages, and procedures** with proper **permissions**.
- Created **jobs** for importing **House Offset** and **ABF data** into **dbmargin**.
- Developed **scripts** to call **dbmarginil procedures** for updating **DAILY_COB_DATE tables**.
- Set up **production directories** for **SANTANDER, SWAPAGENT, and Archive** with proper **permissions**.
- Renamed **Asset Booking table** to `STAGING_COTC_ASSET_BOOKING_HOUSE_DBCS` and updated the **ABF House package**.
- Implemented **House CCPs migration readiness changes**, removing **user confirmations** from all jobs.
- Executed **production deployment** for new **Control-M jobs** for **House ABF** and **Offset report generation**.
- Added all necessary **job dependencies** and applied **775 permissions** to **directories and subdirectories**.
- Created **staging tables** for loading **AHV, SSI, and Asset Booking DBS data**, granting access to **DBM_COTC_USER**.

---

## 4. COTC Migration (Tranche-wise)
- Added **FileWatcher** and **feed import Control-M jobs** for each **CCP**: **LCH SA, LCH FX, Eurex**.
- Inserted **SQL queries** into the **F3Job table** to create **Dbmargin jobs** for feed import.
- Supported **Migration Readiness** from the **CMV perspective** for all **tranches**.
- Created **External Exposures Reset 3 workflow jobs** for **clearingtaskUS**, covering **BlackRock US timing**.
- Updated **Client CCP Migration Readiness** with changes in **F3Jobs**.
- Prepared **Tranche 8 bulk migration** by creating **F3Jobs** for planned agreements.
- Deployed all **scripts** for **agreement updates** for **LCH, Eurex, LCHSA, LCHFX**.
- Added **dependencies** on **Cutoff jobs, DER jobs, and Cashflow Autobooking jobs**.
- Adjusted **FileWatcher** and **import job timings** to prevent **overlaps**.
- Coordinated with **L2 team** to add **Geneous alerts** on incoming **DBCS files** and documented process on **Confluence**.

---

## 5. Control-M Deployment
- Created a **sub-application** for **COTC jobs** under **DBMRGN**.
- Enabled **Control-M alerts** for all **COTC jobs** and **House jobs**.
- Renamed existing **Control-M jobs** to align with new **sequencing** for **EUREX, LCHSA, and LCHFX**.
- Adjusted **FileWatcher** and **import job timings**, adding necessary **dependencies**.
- Created separate **Cutoff jobs** for each **CCP**, including **EUREX Cutoff Job 27**.
- Created a new **F3Job** for **Clearing Task UK**.

---

## 6. Testing and Support
- Developed **scripts** to extract **unique error reasons** from failed agreement records.
- Assisted team in **production release preparation**.
- Supported **DBI Journal Posting analysis and testing** from **House perspective**.
- Provided support during **COTC tranche migrations**, assisting with **deployments** and **issue resolution**.
- Collaborated with **testing team** (Sonali, Neelam, Ravneet) during **EUREX, LCHSA, LCHFX migrations**.
- Provided **daily UAT support** and **technical troubleshooting**.

---

## 7. Others / Additional Contributions
- Supported and **mentored interns, new graduates, and apprentices**.
- Organized and supported **Pune team events**.
- Assisted colleagues with **previous projects** when requested.
- Participated in **sports and CSR events** organized by **Deutsche Bank**.

---
## Testing and Support
- Assisted the **testing team** (Sonali, Neelam, Ravneet) during **EUREX, LCHSA, and LCHFX migrations**, performing end-to-end testing alongside them.  
- Provided **daily support** during **UAT**, troubleshooting any technical challenges and ensuring smooth testing execution.  

## Change Ticket Management
- Raised **Change Tickets** for almost all **weekend deployments** and **mid-week migrations** related to **COTC Migration** consistently throughout the year.  
- Managed **evidence calls**, provided **knowledge transfer (KT)** to **L2**, explained all changes, and addressed counter questions.  
- Coordinated with **JIRA owners** to ensure all changes were properly documented in **TER, binary, and Source Code Reports**, with complete **implementation and rollback plans**.  
- Worked extended hours on **Fridays** to obtain **approvals**, close **SDLC controls**, get **sign-offs**, and ensure **TER closure**.  
- Verified **TBAC passes** for release **JARs**, added **SCR and binary details**, keeping **CRs in approval state**.  
- Deployed changes almost every **Saturday** and collected **post-release evidence**.  
- Ensured all **Change Tickets** were **closed on time**.  

## AWV Contributions
- Temporarily disabled **auto-archive** of **BGS_SETTLEMENT_POSTING table** and moved **Jan 2022 archive data** from history to main table.  
- Updated **BGS_SETTLEMENT_POSTING table** by replacing **Org_ID=0 with 5121431**.  
- Implemented **code changes** to bypass calls to **dbHive FSIP Cache** while processing **COTC Fees & Interests**.  
- Upgraded **AWV services** to **JDK 17.0.13** for all 8 services.  
- Provided **KT on AWV dbmargin flow** to the team.  
- Modified **dbCS file processing logic** to archive repeated files, bypassing saving under **ErrorFiles folder**.  
- Had multiple calls with **Sadivya** over the months to discuss **AWV issues and guidance**.  

## 8. Overall Values & Beliefs
- Completed **mandatory training** on time.
- Regularly attended **office beyond minimum requirements**.
- Contributed **code monthly**.
- Applied for **leave on Workday** timely.
- Took **accountability** for work and decisions.
- Prioritized **supporting colleagues** and fostering a **connected team environment**.
