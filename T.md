# Year-End Review: Key Contributions and Achievements

## 1. CASS Report Development for OPS and Client Service Teams
- Documented business and technical requirements on Confluence.
- Developed a new template for daily exposure data with all required reporting columns.
- Created F3 jobs and Control-M jobs for automated daily report generation.
- Configured DSS flow service to load report data daily into the dbmarginil staging table.
- Created staging and archival tables for data management.
- Implemented stored procedure logic to generate CASS report and scripts to call the procedure for OPS and Client Service teams.
- Enhanced logic to include additional columns (e.g., CCP, FX_RATE) missing from the original DER template.
- Updated DSS configurations, reloaded data, and performed archival testing.
- Implemented Repgen and Control-M changes to ensure smooth report generation.
- Conducted handover session and explained all changes to Rajesh.

## 2. MCUBE Balance Report Development
- Developed stored procedure logic in dbmarginil to load daily price and haircut data.
- Created Control-M jobs and scripts for automation, scheduled Sun–Thu at 9:30 PM EST.
- Generated MCUBE Balance Report, resolving multiple data outliers through testing.
- Built a Java utility to identify discrepancies between DBMargin and DBREX reports.
- Collaborated with Rajesh to align DBREX and MCUBE reporting flows.
- Conducted parallel production tests and deployments for performance and data validation.
- Provided KT to MCUBE team, incorporated feedback, and obtained sign-off.
- Enhanced feed to convert As_of_date into yyyy-MM-dd format.
- Optimized performance:
  - Aggregated 60-day-old balances into local tables.
  - Archived 2-month-old price and haircut data into history tables.
  - Added table partitioning, reducing report time to under 12 minutes.
  - Automated archival for data older than 65 business days.

## 3. House Development
- Built logic in cs-post-ingestion-service to handle GET requests with query parameters.
- Deployed tables, views, types, sequences, packages, and procedures with proper permissions.
- Created jobs for importing House Offset and ABF data.
- Developed scripts to call dbmarginil procedures for DAILY_COB_DATE updates.
- Set up production directories for SANTANDER, SWAPAGENT, and Archive with proper permissions.
- Renamed Asset Booking table to STAGING_COTC_ASSET_BOOKING_HOUSE_DBCS and updated ABF House package.
- Implemented House CCP migration readiness changes and removed user confirmations.
- Deployed new Control-M jobs for House ABF and Offset report generation.
- Added job dependencies and applied 775 permissions to directories.
- Created staging tables for AHV, SSI, and Asset Booking DBS data, granting access to DBM_COTC_USER.

## 4. COTC Migration (Tranche-wise)
- Added FileWatcher and feed import Control-M jobs for LCH SA, LCH FX, and Eurex.
- Inserted SQL queries into F3Job table for Dbmargin feed jobs.
- Supported Migration Readiness from CMV perspective for all tranches.
- Created External Exposures Reset 3 workflow jobs for clearingtaskUS covering BlackRock US timing.
- Updated Client CCP Migration Readiness with F3Job changes.
- Prepared Tranche 8 bulk migration by creating F3Jobs for planned agreements.
- Deployed scripts for agreement updates for LCH, Eurex, LCHSA, LCHFX.
- Added dependencies on Cutoff jobs, DER jobs, and Cashflow Autobooking jobs.
- Adjusted FileWatcher and import timings to prevent overlaps.
- Coordinated with L2 team to add Geneous alerts on incoming DBCS files and documented on Confluence.

## 5. Control-M Deployment
- Created a sub-application for COTC jobs under DBMRGN.
- Enabled Control-M alerts for COTC and House jobs.
- Renamed existing Control-M jobs for EUREX, LCHSA, and LCHFX sequencing.
- Adjusted FileWatcher and import job timings and added dependencies.
- Created separate Cutoff jobs for each CCP, including EUREX Cutoff Job 27.
- Created a new F3Job for Clearing Task UK.

## 6. Testing and Support
- Developed scripts to extract unique error reasons from failed agreement records.
- Assisted team in production release preparation.
- Supported DBI Journal Posting analysis and testing from House perspective.
- Assisted during COTC tranche migrations with deployments and issue resolution.
- Collaborated with testing team (Sonali, Neelam, Ravneet) during EUREX, LCHSA, LCHFX migrations.
- Provided daily UAT support and troubleshooting.

## 7. Others / Additional Contributions
- Supported and mentored interns, new graduates, and apprentices.
- Organized and supported Pune team events.
- Assisted colleagues with previous projects.
- Participated in sports and CSR events organized by Deutsche Bank.

## 8. Overall Values & Beliefs
- Completed mandatory training on time.
- Regularly attended office beyond minimum requirements.
- Contributed code monthly.
- Applied for leave on Workday timely.
- Took accountability for work and decisions.
- Prioritized supporting colleagues and fostering a connected team environment.
