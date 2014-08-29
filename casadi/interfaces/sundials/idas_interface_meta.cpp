/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010 by Joel Andersson, Moritz Diehl, K.U.Leuven. All rights reserved.
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


      #include "idas_interface.hpp"
      #include <string>

      const std::string casadi::IdasInterface::meta_doc=
      "\n"
"Interface to IDAS from the Sundials suite.\n"
"\n"
"\n"
">List of available options\n"
"\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"|       Id        |      Type       |     Default     |   Description   |\n"
"+=================+=================+=================+=================+\n"
"| abstol          | OT_REAL         | 0.000           | Absolute        |\n"
"|                 |                 |                 | tolerence for   |\n"
"|                 |                 |                 | the IVP         |\n"
"|                 |                 |                 | solution        |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| abstolB         | OT_REAL         | GenericType()   | Absolute        |\n"
"|                 |                 |                 | tolerence for   |\n"
"|                 |                 |                 | the adjoint     |\n"
"|                 |                 |                 | sensitivity     |\n"
"|                 |                 |                 | solution        |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to abstol]      |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| abstolv         | OT_REALVECTOR   |                 |                 |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| calc_ic         | OT_BOOLEAN      | true            | Use IDACalcIC   |\n"
"|                 |                 |                 | to get          |\n"
"|                 |                 |                 | consistent      |\n"
"|                 |                 |                 | initial         |\n"
"|                 |                 |                 | conditions.     |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| calc_icB        | OT_BOOLEAN      | GenericType()   | Use IDACalcIC   |\n"
"|                 |                 |                 | to get          |\n"
"|                 |                 |                 | consistent      |\n"
"|                 |                 |                 | initial         |\n"
"|                 |                 |                 | conditions for  |\n"
"|                 |                 |                 | backwards       |\n"
"|                 |                 |                 | system          |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to calc_ic].    |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| cj_scaling      | OT_BOOLEAN      | false           | IDAS scaling on |\n"
"|                 |                 |                 | cj for the      |\n"
"|                 |                 |                 | user-defined    |\n"
"|                 |                 |                 | linear solver   |\n"
"|                 |                 |                 | module          |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| disable_interna | OT_BOOLEAN      | false           | Disable IDAS    |\n"
"| l_warnings      |                 |                 | internal        |\n"
"|                 |                 |                 | warning         |\n"
"|                 |                 |                 | messages        |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| exact_jacobian  | OT_BOOLEAN      | true            | Use exact       |\n"
"|                 |                 |                 | Jacobian        |\n"
"|                 |                 |                 | information for |\n"
"|                 |                 |                 | the forward     |\n"
"|                 |                 |                 | integration     |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| exact_jacobianB | OT_BOOLEAN      | GenericType()   | Use exact       |\n"
"|                 |                 |                 | Jacobian        |\n"
"|                 |                 |                 | information for |\n"
"|                 |                 |                 | the backward    |\n"
"|                 |                 |                 | integration     |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to              |\n"
"|                 |                 |                 | exact_jacobian] |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| extra_fsens_cal | OT_BOOLEAN      | false           | Call calc ic an |\n"
"| c_ic            |                 |                 | extra time,     |\n"
"|                 |                 |                 | with fsens=0    |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| finite_differen | OT_BOOLEAN      | false           | Use finite      |\n"
"| ce_fsens        |                 |                 | differences to  |\n"
"|                 |                 |                 | approximate the |\n"
"|                 |                 |                 | forward         |\n"
"|                 |                 |                 | sensitivity     |\n"
"|                 |                 |                 | equations (if   |\n"
"|                 |                 |                 | AD is not       |\n"
"|                 |                 |                 | available)      |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| first_time      | OT_REAL         | GenericType()   | First requested |\n"
"|                 |                 |                 | time as a       |\n"
"|                 |                 |                 | fraction of the |\n"
"|                 |                 |                 | time interval   |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| fsens_abstol    | OT_REAL         | GenericType()   | Absolute        |\n"
"|                 |                 |                 | tolerence for   |\n"
"|                 |                 |                 | the forward     |\n"
"|                 |                 |                 | sensitivity     |\n"
"|                 |                 |                 | solution        |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to abstol]      |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| fsens_abstolv   | OT_REALVECTOR   |                 |                 |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| fsens_err_con   | OT_BOOLEAN      | true            | include the     |\n"
"|                 |                 |                 | forward         |\n"
"|                 |                 |                 | sensitivities   |\n"
"|                 |                 |                 | in all error    |\n"
"|                 |                 |                 | controls        |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| fsens_reltol    | OT_REAL         | GenericType()   | Relative        |\n"
"|                 |                 |                 | tolerence for   |\n"
"|                 |                 |                 | the forward     |\n"
"|                 |                 |                 | sensitivity     |\n"
"|                 |                 |                 | solution        |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to reltol]      |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| fsens_scaling_f | OT_REALVECTOR   | GenericType()   | Scaling factor  |\n"
"| actors          |                 |                 | for the         |\n"
"|                 |                 |                 | components if   |\n"
"|                 |                 |                 | finite          |\n"
"|                 |                 |                 | differences is  |\n"
"|                 |                 |                 | used            |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| fsens_sensitivi | OT_INTEGERVECTO | GenericType()   | Specifies which |\n"
"| y_parameters    | R               |                 | components will |\n"
"|                 |                 |                 | be used when    |\n"
"|                 |                 |                 | estimating the  |\n"
"|                 |                 |                 | sensitivity     |\n"
"|                 |                 |                 | equations       |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| init_xdot       | OT_REALVECTOR   | GenericType()   | Initial values  |\n"
"|                 |                 |                 | for the state   |\n"
"|                 |                 |                 | derivatives     |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| interpolation_t | OT_STRING       | \"hermite\"       | Type of         |\n"
"| ype             |                 |                 | interpolation   |\n"
"|                 |                 |                 | for the adjoint |\n"
"|                 |                 |                 | sensitivities ( |\n"
"|                 |                 |                 | hermite|polynom |\n"
"|                 |                 |                 | ial)            |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| iterative_solve | OT_STRING       | \"gmres\"         | (gmres|bcgstab| |\n"
"| r               |                 |                 | tfqmr)          |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| iterative_solve | OT_STRING       | GenericType()   | (gmres|bcgstab| |\n"
"| rB              |                 |                 | tfqmr)          |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| linear_solver   | OT_STRING       | GenericType()   | A custom linear |\n"
"|                 |                 |                 | solver creator  |\n"
"|                 |                 |                 | function        |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| linear_solverB  | OT_STRING       | GenericType()   | A custom linear |\n"
"|                 |                 |                 | solver creator  |\n"
"|                 |                 |                 | function for    |\n"
"|                 |                 |                 | backwards       |\n"
"|                 |                 |                 | integration     |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to              |\n"
"|                 |                 |                 | linear_solver]  |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| linear_solver_o | OT_DICTIONARY   | GenericType()   | Options to be   |\n"
"| ptions          |                 |                 | passed to the   |\n"
"|                 |                 |                 | linear solver   |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| linear_solver_o | OT_DICTIONARY   | GenericType()   | Options to be   |\n"
"| ptionsB         |                 |                 | passed to the   |\n"
"|                 |                 |                 | linear solver   |\n"
"|                 |                 |                 | for backwards   |\n"
"|                 |                 |                 | integration     |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to linear_solve |\n"
"|                 |                 |                 | r_options]      |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| linear_solver_t | OT_STRING       | \"dense\"         | (user_defined|d |\n"
"| ype             |                 |                 | ense|banded|ite |\n"
"|                 |                 |                 | rative)         |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| linear_solver_t | OT_STRING       | GenericType()   | (user_defined|d |\n"
"| ypeB            |                 |                 | ense|banded|ite |\n"
"|                 |                 |                 | rative)         |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| lower_bandwidth | OT_INTEGER      | GenericType()   | Lower band-     |\n"
"|                 |                 |                 | width of banded |\n"
"|                 |                 |                 | Jacobian        |\n"
"|                 |                 |                 | (estimations)   |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| lower_bandwidth | OT_INTEGER      | GenericType()   | lower band-     |\n"
"| B               |                 |                 | width of banded |\n"
"|                 |                 |                 | jacobians for   |\n"
"|                 |                 |                 | backward        |\n"
"|                 |                 |                 | integration     |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to lower_bandwi |\n"
"|                 |                 |                 | dth]            |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| max_krylov      | OT_INTEGER      | 10              | Maximum Krylov  |\n"
"|                 |                 |                 | subspace size   |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| max_krylovB     | OT_INTEGER      | GenericType()   | Maximum krylov  |\n"
"|                 |                 |                 | subspace size   |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| max_multistep_o | OT_INTEGER      | 5               |                 |\n"
"| rder            |                 |                 |                 |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| max_num_steps   | OT_INTEGER      | 10000           | Maximum number  |\n"
"|                 |                 |                 | of integrator   |\n"
"|                 |                 |                 | steps           |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| max_step_size   | OT_REAL         | 0               | Maximim step    |\n"
"|                 |                 |                 | size            |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| pretype         | OT_STRING       | \"none\"          | (none|left|righ |\n"
"|                 |                 |                 | t|both)         |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| pretypeB        | OT_STRING       | GenericType()   | (none|left|righ |\n"
"|                 |                 |                 | t|both)         |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| quad_err_con    | OT_BOOLEAN      | false           | Should the      |\n"
"|                 |                 |                 | quadratures     |\n"
"|                 |                 |                 | affect the step |\n"
"|                 |                 |                 | size control    |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| reltol          | OT_REAL         | 0.000           | Relative        |\n"
"|                 |                 |                 | tolerence for   |\n"
"|                 |                 |                 | the IVP         |\n"
"|                 |                 |                 | solution        |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| reltolB         | OT_REAL         | GenericType()   | Relative        |\n"
"|                 |                 |                 | tolerence for   |\n"
"|                 |                 |                 | the adjoint     |\n"
"|                 |                 |                 | sensitivity     |\n"
"|                 |                 |                 | solution        |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to reltol]      |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| sensitivity_met | OT_STRING       | \"simultaneous\"  | (simultaneous|s |\n"
"| hod             |                 |                 | taggered)       |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| steps_per_check | OT_INTEGER      | 20              | Number of steps |\n"
"| point           |                 |                 | between two     |\n"
"|                 |                 |                 | consecutive     |\n"
"|                 |                 |                 | checkpoints     |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| stop_at_end     | OT_BOOLEAN      | true            | Stop the        |\n"
"|                 |                 |                 | integrator at   |\n"
"|                 |                 |                 | the end of the  |\n"
"|                 |                 |                 | interval        |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| suppress_algebr | OT_BOOLEAN      | false           | Supress         |\n"
"| aic             |                 |                 | algebraic       |\n"
"|                 |                 |                 | variables in    |\n"
"|                 |                 |                 | the error       |\n"
"|                 |                 |                 | testing         |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| upper_bandwidth | OT_INTEGER      | GenericType()   | Upper band-     |\n"
"|                 |                 |                 | width of banded |\n"
"|                 |                 |                 | Jacobian        |\n"
"|                 |                 |                 | (estimations)   |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| upper_bandwidth | OT_INTEGER      | GenericType()   | Upper band-     |\n"
"| B               |                 |                 | width of banded |\n"
"|                 |                 |                 | jacobians for   |\n"
"|                 |                 |                 | backward        |\n"
"|                 |                 |                 | integration     |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to upper_bandwi |\n"
"|                 |                 |                 | dth]            |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| use_preconditio | OT_BOOLEAN      | false           | Precondition an |\n"
"| ner             |                 |                 | iterative       |\n"
"|                 |                 |                 | solver          |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| use_preconditio | OT_BOOLEAN      | GenericType()   | Precondition an |\n"
"| nerB            |                 |                 | iterative       |\n"
"|                 |                 |                 | solver for the  |\n"
"|                 |                 |                 | backwards       |\n"
"|                 |                 |                 | problem         |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to use_precondi |\n"
"|                 |                 |                 | tioner]         |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"\n"
"\n"
">List of available monitors\n"
"\n"
"+--------------------------+\n"
"|            Id            |\n"
"+==========================+\n"
"| bjacB                    |\n"
"+--------------------------+\n"
"| correctInitialConditions |\n"
"+--------------------------+\n"
"| jtimesB                  |\n"
"+--------------------------+\n"
"| psetup                   |\n"
"+--------------------------+\n"
"| psetupB                  |\n"
"+--------------------------+\n"
"| psolveB                  |\n"
"+--------------------------+\n"
"| res                      |\n"
"+--------------------------+\n"
"| resB                     |\n"
"+--------------------------+\n"
"| resS                     |\n"
"+--------------------------+\n"
"| rhsQB                    |\n"
"+--------------------------+\n"
"\n"
"\n"
">List of available stats\n"
"\n"
"+-------------+\n"
"|     Id      |\n"
"+=============+\n"
"| nlinsetups  |\n"
"+-------------+\n"
"| nlinsetupsB |\n"
"+-------------+\n"
"| nsteps      |\n"
"+-------------+\n"
"| nstepsB     |\n"
"+-------------+\n"
"\n"
"\n"
"\n"
"\n"
;
