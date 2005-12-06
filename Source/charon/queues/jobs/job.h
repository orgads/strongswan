/**
 * @file job.h
 * 
 * @brief Interface job_t.
 * 
 */

/*
 * Copyright (C) 2005 Jan Hutter, Martin Willi
 * Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#ifndef JOB_H_
#define JOB_H_

#include <types.h>
#include <definitions.h>


typedef enum job_type_t job_type_t;

/**
 * @brief Definition of the various job types.
 * 
 * @todo add more jobs, such as rekeying.
 * 
 * @ingroup jobs
 */
enum job_type_t {
	/** 
	 * Process an incoming IKEv2-Message.
	 * 
 	 * Job is implemented in class type incoming_packet_job_t
	 */
	INCOMING_PACKET,
	
	/** 
	 * Retransmit an IKEv2-Message.
	 */
	RETRANSMIT_REQUEST,
	
	/** 
	 * Establish an ike sa as initiator.
	 * 
	 * Job is implemented in class type initiate_ike_sa_job_t
	 */
	INITIATE_IKE_SA,
	
	/** 
	 * Delete an ike sa which is still not established.
	 * 
	 * Job is implemented in class type delete_half_open_ike_sa_job_t
	 */
	DELETE_HALF_OPEN_IKE_SA,
	
	/** 
	 * Delete an ike sa which is established.
	 * 
	 * Job is implemented in class type delete_established_ike_sa_job_t
	 */	
	DELETE_ESTABLISHED_IKE_SA
};

/**
 * string mappings for job_type_t
 * 
 * @ingroup jobs
 */
extern mapping_t job_type_m[];


typedef struct job_t job_t;

/**
 * @brief Job-Interface as it is stored in the job queue.
 * 
 * A job consists of a job-type and one or more assigned values.
 * 
 * @b Constructors:
 * - None, use specific implementation of the interface.
 * 
 * @ingroup jobs
 */
struct job_t {

	/**
	 * @brief get type of job.
	 *
	 * @param this 				calling object
	 * @return 					type of this job
	 */
	job_type_t (*get_type) (job_t *this);

	/**
	 * @brief Destroys a job_t object and all assigned data!
	 * 
	 * @param job_t calling object
	 */
	void (*destroy_all) (job_t *job);

	/**
	 * @brief Destroys a job_t object
	 * 
	 * @param job_t calling object
	 */
	void (*destroy) (job_t *job);
};


#endif /*JOB_H_*/
